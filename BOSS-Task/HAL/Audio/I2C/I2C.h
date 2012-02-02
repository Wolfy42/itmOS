/*
 * I2C.h
 *
 *  Created on: Dec 21, 2011
 *      Author: Stefan Gassner (Thomas Bargetz)
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

#include "API/dataTypes.h"

#define MMIO_WRITE32(addr, data) \
  (*((mem_address_t *) addr) = data)

//#define reg16w(b, r, v) (*((volatile uint16_t *)((b)+(r))) = (v))
#define MMIO_WRITE16(addr, data) \
  (*((volatile uint16_t *)(addr)) = data)

#define MMIO_OR32(addr, or_data) \
  (*((mem_address_t *) addr) |= or_data)

#define MMIO_OR16(addr, or_data) \
  (*((volatile uint16_t *) addr) |= or_data)

#define MMIO_AND32(addr, and_data) \
  (*((mem_address_t *) addr) &= and_data)

#define MMIO_AND16(addr, and_data) \
  (*((volatile uint16_t *) addr) &= and_data)

#define MMIO_AND_THEN_OR32(addr, and_data, or_data) \
  MMIO_AND32(addr, and_data); \
  MMIO_OR32(addr, or_data)

#define MMIO_AND_THEN_OR16(addr, and_data, or_data) \
  MMIO_AND16(addr, and_data); \
  MMIO_OR16(addr, or_data)

#define MMIO_READ32(addr) *((mem_address_t *) addr)

//#define reg16r(b, r) (*(volatile uint16_t *)((b)+(r)))
#define MMIO_READ16(addr) (*(volatile uint16_t *)(addr)) //*((volatile uint16_t *) addr)

/* I2C base addresses */
#define I2C1_BASE 0x48070000
#define I2C2_BASE 0x48072000
#define I2C3_BASE 0x48060000

/* I2C register offsets */
#define I2C_REV     0x00  /* revision register */
#define I2C_IE      0x04
#define I2C_STAT    0x08
#define I2C_WE      0x0C
#define I2C_SYSS    0x10
#define I2C_BUF     0x14
#define I2C_CNT     0x18
#define I2C_DATA    0x1C
#define I2C_SYSC    0x20
#define I2C_CON     0x24
#define I2C_OA0     0x28
#define I2C_SA      0x2C
#define I2C_PSC     0x30
#define I2C_SCLL    0x34
#define I2C_SCLH    0x38
#define I2C_SYSTEST 0x3C
#define I2C_BUFSTAT 0x40
#define I2C_OA1     0x44
#define I2C_OA2     0x48
#define I2C_OA3     0x4C
#define I2C_ACTOA   0x50
#define I2C_SBLOCK  0x54

// I2C_STAT bits
#define I2C_STAT_XDR (1<<14)
#define I2C_STAT_RDR (1<<13)
#define I2C_STAT_BB (1<<12)
#define I2C_STAT_XRDY (1<<4)
#define I2C_STAT_RRDY (1<<3)
#define I2C_STAT_ARDY (1<<2)
#define I2C_STAT_NACK (1<<1)
#define I2C_STAT_AL (1<<0)
// I2C_CON bits
#define I2C_CON_MST (1<<10)
#define I2C_CON_TRX (1<<9)
#define I2C_CON_STP 2
#define I2C_CON_STT 1

/* i2c bus */
void i2c_init(void);
void i2c_read(uint32_t base, uint8_t sa, uint8_t addr, uint8_t *buffer, int count);
// address stored as first byte(s) of buffer
void i2c_write(uint32_t base, uint8_t sa, uint8_t *buffer, int count);
// write 8 bits
void i2c_write8(uint32_t base, uint8_t sa, uint8_t addr, uint8_t v);

#endif /* I2C_H_ */
