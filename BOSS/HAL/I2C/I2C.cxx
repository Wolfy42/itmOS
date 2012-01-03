/*
 * I2C.cxx
 *
 *  Created on: Dec 21, 2011
 *      Author: Stefan Gassner (Thomas Bargetz)
 */

#include "HAL/I2C/I2C.h"
#include "API/dataTypes.h"
#include <stdint.h>

#define TIMEOUT 10000

/* CORE_CM registers S 4.14.1.5 */
#define CM_CORE_BASE 0x48004A00

#define CM_FCLKEN1_CORE 0x00000000
#define CM_ICLKEN1_CORE 0x00000010
// These bits apply to all of the (CM|PM)*1_CORE registers as EN_, ST_, and AUTO_* bits
#define CM_CORE_EN_I2C1 (1<<15)

static void waitidle(uint32_t base) {
  int timeout;

  // wait for bus-busy off
  timeout = TIMEOUT * 10;
  while (MMIO_READ16(base + I2C_STAT) & I2C_STAT_BB) {
    if (!timeout--) {
      return;
    }
  }
}

// i2c state machine
// used for read or write or parts thereof
// con indicates what to do
//
// See OMAP TRM S 18.5.1.3: Figure 18-29 `I2C Master Transmitter Mode, Polling Method'
static void executeStateMachine(uint32_t base, uint16_t con, uint8_t sa, uint8_t *buffer,
                 int count) {
  int timeout;
  uint16_t st;
  int i = 0;
  bool redoreg = true;

  do {
    MMIO_WRITE16(base + I2C_SA, sa);
    MMIO_WRITE16(base + I2C_CNT, count);
    MMIO_WRITE16(base + I2C_CON, con);

    timeout = TIMEOUT * 10;

    while (i < count) {
      st = MMIO_READ16(base + I2C_STAT);

      if (st & I2C_STAT_NACK) {
        MMIO_WRITE16(base + I2C_STAT, I2C_STAT_NACK);
        break;
        //goto redoreg;
      } else if (st & I2C_STAT_AL) {
        MMIO_WRITE16(base + I2C_STAT, I2C_STAT_AL);
        break;
        //goto redoreg;
      } else if (st & I2C_STAT_ARDY) {
        MMIO_WRITE16(base + I2C_STAT, I2C_STAT_ARDY);
        continue;
      } else if (st & I2C_STAT_RDR) {
        // not sure if i need this ...
        MMIO_WRITE16(base + I2C_STAT, I2C_STAT_XDR);

        redoreg = false;
      } else if (st & I2C_STAT_XRDY) {
        MMIO_WRITE16(base + I2C_DATA, buffer[i++]);
        MMIO_WRITE16(base + I2C_STAT, I2C_STAT_XRDY);

        redoreg = false;
      } else if (st & I2C_STAT_RRDY) {
        buffer[i++] = MMIO_READ16(base + I2C_DATA);
        MMIO_WRITE16(base + I2C_STAT, I2C_STAT_RRDY);

        redoreg = false;
      } else if (timeout-- == 0) {
        return;
      }
    }
  } while (redoreg == true);

  // wait for transfer complete?
  timeout = TIMEOUT;
  while ((MMIO_READ16(base + I2C_STAT) & I2C_STAT_ARDY) == 0)
    if (!timeout--) {
      return;
    }
  MMIO_WRITE16(base + I2C_STAT, I2C_STAT_ARDY);
}

void i2c_read(uint32_t base, uint8_t sa, uint8_t addr, uint8_t *buffer,
                  int count) {
  waitidle(base);
  // send address with no stop
  executeStateMachine(base, 0x8601, sa, &addr, 1);
  // send rest with stop
  executeStateMachine(base, 0x8403, sa, buffer, count);
}

// address encoded in buffer
void i2c_write(uint32_t base, uint8_t sa, uint8_t *buffer, int count) {
  waitidle(base);
  executeStateMachine(base, 0x8603, sa, buffer, count);
}

void i2c_write8(uint32_t base, uint8_t sa, uint8_t addr, uint8_t v) {
  uint8_t buffer[2];// = { addr, v };
  buffer[0] = addr;
  buffer[1] = v;

  i2c_write(base, sa, buffer, 2);
}

void i2c_init(void) {
  uint32_t address = CM_CORE_BASE + CM_FCLKEN1_CORE;

  // enable i2c1 (ROM has alredy done it, but may as well make sure)
  MMIO_AND_THEN_OR32(address, ~CM_CORE_EN_I2C1, CM_CORE_EN_I2C1);
  MMIO_AND_THEN_OR32(address, ~CM_ICLKEN1_CORE, CM_CORE_EN_I2C1);

  // Sets I2C speed to 100Khz F/S mode
  MMIO_WRITE16(I2C1_BASE + I2C_PSC, 0x17);
  MMIO_WRITE16(I2C1_BASE + I2C_SCLL, 0x0d);
  MMIO_WRITE16(I2C1_BASE + I2C_SCLH, 0x0f);
}
