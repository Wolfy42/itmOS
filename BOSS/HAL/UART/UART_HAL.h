

/*
 * UART module base addresses
 * Size 1 Kb
 */
#define UART1 0x4806A000 /* UART only */
#define UART2 0x4806C000 /* UART only */
#define UART3 0x49020000 /* UART, IrDA, CIR */

/*
 * UART Registers offset
 * 8 bit width
 */
#define UART_DLL_REG        0x000 /* RW */
#define UART_RHR_REG        0x000 /* R FIFO read */
#define UART_THR_REG        0x000 /* W FIFO transmission */
#define UART_DLH_REG        0x004 /* RW */
#define UART_IER_REG        0x004 /* RW */

#define UART_IER_RHR_IT       0
#define UART_IER_THR_IT       1
#define UART_IER_LINE_STS_IT  2
#define UART_IER_MODEM_STS_IT 3
#define UART_IER_SLEEP_MODE   4
#define UART_IER_XOFF_IT      5
#define UART_RTS_IT           6
#define UART_CTS_IT           7

#define UART_IIR_REG        0x008 /* R */
#define UART_FCR_REG        0x008 /* W FIFO Control */

#define UART_FCR_FIFO_EN        0
#define UART_FCR_RX_FIFO_CLEAR  1
#define UART_FCR_TX_FIFO_CLEAR  2
#define UART_FCR_DMA_MODE       3

// TODO: delete the following lines and replace them by the commented
// UART_FCR_RX_TRIG_xx etc.
#define UART_FCR_TX_FIFO_TRIG_1 4
#define UART_FCR_TX_FIFO_TRIG_2 5
#define UART_FCR_RX_FIFO_TRIG_1 6
#define UART_FCR_RX_FIFO_TRIG_2 7
// TODO: find a way to use flags in the following way
//#define UART_FCR_RX_TRIG_00      0x00
//#define UART_FCR_RX_TRIG_01      0x40
//#define UART_FCR_RX_TRIG_10      0x80
//#define UART_FCR_RX_TRIG_11      0xC0
//#define UART_FCR_TX_TRIG_00      0x00
//#define UART_FCR_TX_TRIG_01      0x10
//#define UART_FCR_TX_TRIG_10      0x20
//#define UART_FCR_TX_TRIG_11      0x30


#define UART_EFR_REG        0x008 /* RW */

/* bit specification of the UART EFR register */
#define UART_EFR_SWFC_0       0
#define UART_EFR_SWFC_1       1
#define UART_EFR_SWFC_2       2
#define UART_EFR_SWFC_3       3
#define UART_EFR_ENHANCED_EN  4
#define UART_EFR_SPEC_CHAR    5
#define UART_EFR_AUTO_RTS_EN  6
#define UART_EFR_AUTO_CTS_EN  7

#define UART_LCR_REG        0x00C /* RW */

/* UART LCR Configuration mode */
#define UART_LCR_MODE_CONFIG_A 0x0080
#define UART_LCR_MODE_CONFIG_B 0x00BF
#define UART_LCR_MODE_REG_OP   0x0000
/* UART LCR register bits*/
#define UART_LCR_CHAR_LEN_0 0 /* 0 and 1 bit */
#define UART_LCR_CHAR_LEN_1 1
#define UART_LCR_NB_STOP    2
#define UART_LCR_PARITY_EN  3
#define UART_LCR_PARITY_T1  4
#define UART_LCR_PARITY_T2  5
#define UART_LCR_BREAK_EN   6
#define UART_LCR_DIV_EN     7


#define UART_MCR_REG        0x010 /* RW Modem Control */

#define UART_MCR_TCR_TLR    6
#define UART_MCR_LOOPBACK_EN 0x10


#define UART_XON1_ADDR1_REG 0x010 /* RW */
#define UART_LSR_REG        0x014 /* R */

#define UART_LSR_RX_FIFO_E  0 /* 0 BIT */
#define UART_LSR_TX_FIFO_E  5 /* 5 BIT */
#define UART_LSR_TX_SR_E    6 /* 6 BIT */


#define UART_XON2_ADDR2_REG 0x014 /* RW */
#define UART_MSR_REG        0x018 /* R */
#define UART_TCR_REG        0x018 /* RW */
#define UART_XOFF1_REG      0x018 /* RW */
#define UART_SPR_REG        0x01C /* RW */
#define UART_TLR_REG        0x01C /* RW */
#define UART_XOFF2_REG      0x01C /* RW */
#define UART_MDR1_REG       0x020 /* RW Mode Definition CIR/IrDA */

/* UART Mode Select */
#define UART_MDR1_MODE_SELECT_16X          0x000
#define UART_MDR1_MODE_SELECT_SIR          0x001
#define UART_MDR1_MODE_SELECT_16X_AUTOBAUD 0x002
#define UART_MDR1_MODE_SELECT_13X          0x003
#define UART_MDR1_MODE_SELECT_MIR          0x004
#define UART_MDR1_MODE_SELECT_FIR          0x005
#define UART_MDR1_MODE_SELECT_CIR          0x006
#define UART_MDR1_MODE_SELECT_DISABLE      0x007

#define UART_MDR2_REG       0x024 /* RW */
#define UART_SFLSR_REG      0x028 /* R */
#define UART_UASR_REG       0x038 /* R */
#define UART_BLR_REG        0x038 /* RW */

#define UART_SCR_REG        0x040 /* RW Supplementary Control */

#define UART_SCR_DMA_MODE_CTL   0
#define UART_SCR_DMA_MODE_2_0   1
#define UART_SCR_DMA_MODE_2_1   2
#define UART_SCR_RX_TRIG_GRANU1 7
#define UART_SCR_TX_TRIG_GRANU1 6

#define UART_SSR_REG        0x044 /* R */

#define UART_SSR_TX_FIFO_FULL 0

#define UART_MVR_REG        0x050 /* R */
#define UART_SYSC_REG       0x054 /* RW */
#define UART_SYSS_REG       0x058 /* R */
#define UART_WER_REG        0x05C /* RW */


/*
 * UART3 specific registers offset
 * 8 bit width
 */
#define UART3_TXFLL_REG     0x028 /* W */
#define UART3_RESUME_REG    0x02C /* R */
#define UART3_TXFLH_REG     0x02C /* W */
#define UART3_SFREGL_REG    0x030 /* R */
#define UART3_RXFLL_REG     0x030 /* W */
#define UART3_SFREGH_REG    0x034 /* R */
#define UART3_RXFLH_REG     0x034 /* W */
#define UART3_ACREG_REG     0x03C /* RW */
#define UART3_EBLR_REG      0x048 /* RW */
#define UART3_CFPS_REG      0x060 /* RW */



#define UART_PROTOCOL_BAUDRATE_16X115_2 0x001A

#define UART_PROTOCOL_DATA_LENGTH_5     0x0
#define UART_PROTOCOL_DATA_LENGTH_6     0x1
#define UART_PROTOCOL_DATA_LENGTH_7     0x2
#define UART_PROTOCOL_DATA_LENGTH_8     0x3

#define UART_PROTOCOL_NB_STOP_1         0x0
#define UART_PROTOCOL_NB_STOP_2         0x1

/* TODO(ramsondon@gmail.com) add more parity types.
 * for PARITY_TYPE 1 and 2 configurations
 */
#define UART_PROTOCOL_PARITY_NONE       0x0

#define UART_FLOW_CONTROL_DISABLE_FLAG  0x0


/* UART Modes */
#define UART_MODE_13X          UART_MDR1_MODE_SELECT_13X
#define UART_MODE_16X          UART_MDR1_MODE_SELECT_16X
#define UART_MODE_16X_AUTOBAUD UART_MDR1_MODE_SELECT_16X_AUTOBAUD
#define UART_MODE_SIR          UART_MDR1_MODE_SELECT_SIR
#define UART_MODE_MIR          UART_MDR1_MODE_SELECT_MIR
#define UART_MODE_FIR          UART_MDR1_MODE_SELECT_FIR
#define UART_MODE_CIR          UART_MDR1_MODE_SELECT_CIR
#define UART_MODE_DISABLE      UART_MDR1_MODE_SELECT_DISABLE




// TODO: lol @ this?
typedef volatile unsigned int mem_address_t;
typedef unsigned char uint8_t;

/*
 * UART protocol format
 */
typedef struct uart_protocol_format_t {
    unsigned int baudrate;
    unsigned short datalen;
    unsigned short stopbit;
    unsigned int parity;
} uart_protocol_format_t;

/*
 * UART RS232 configuration
 * BAUD RATE: 115200
 * DATA: 8 bit
 * PARITY: none
 * STOP: 1bit
 * FLOW CONTROL: none (Critical)
 */

static struct uart_protocol_format_t uart_protocol_rs232 = {
  UART_PROTOCOL_BAUDRATE_16X115_2,
  UART_PROTOCOL_DATA_LENGTH_8,
  UART_PROTOCOL_NB_STOP_1,
  UART_PROTOCOL_PARITY_NONE
};


/*
 * Inits UART module uart_base_addr. Use defines (mem_address_t*) UART1, UART2,
 * or UART3.
 */
void uart_init(mem_address_t* uart_base_addr, int uart_mode,
               struct uart_protocol_format_t protocol,
               uint8_t flowcontrol);

/*
 * Disables UART and initiates a software reset
 */
void uart_reset(mem_address_t* uart_base_addr);

/*
 * Necessary for FIFO configuration. Sets Config Mode A (0x0080) into LCR
 * register.
 */
void uart_switch_to_config_mode_a(mem_address_t* uart_base_addr);

/* Sets Config Mode B (0x00BF) into LCR register to setup protocol format */
void uart_switch_to_config_mode_b(mem_address_t* uart_base_addr);

/* Sets operational Mode (0x0000) to LCR register */
void uart_switch_to_register_operational_mode(mem_address_t* uart_base_addr);

/*
 * Sets the baudrate. DHL and DLL register MUST be 0x0000 before calling this
 * function.
 */
void uart_set_baudrate(mem_address_t* uart_base_addr, int baudrate);

/*
 * The UART mode to run the uart_base_addr UART unit.
 * Use UART_MODE_xxx as params.
 */
void uart_set_mode(mem_address_t* uart_base_addr, int uart_mode);

/*
 * @see: uart_protocol_rs232
 */
void uart_set_protocol_format(mem_address_t* uart_base_addr,
                              uart_protocol_format_t protocol);

/*
 * Use in Config Mode B
 */
void uart_set_flow_control(mem_address_t* uart_base_addr, uint8_t flow_control);

/*
 * Enables enhanced functionality register access.
 */
void uart_enable_enhanced_func(mem_address_t* uart_base_addr);

/*
 * Enables the access to the MCR (Modem Controller) TCR_TLR register.
 * uart_enable_enhanced_func() MUST be called first.
 */
void uart_enable_tcr(mem_address_t* uart_base_addr);


/*
 * Writes one character to the UART device. This function does not check if the
 * transmission queue is empty. check with uart_is_empty_write_queue() for
 * all bytes to write.
 */
void uart_write(mem_address_t* uart_base_addr, char* buffer);

/*
 * Reads one character from the UART device into the buffer. This function does
 * not check if the receive queue is empty. check with
 * uart_is_empty_read_queue() for all bytes to read.
 */
void uart_read(mem_address_t* uart_base_addr, char* buffer);

/*
 * Returns 1 if the UART transmission queue is empty, else 0
 */
int uart_is_empty_write_queue(mem_address_t* uart_base_addr);

/*
 * Returns 1 if the UART receiving queue is empty, else 0
 */
int uart_is_empty_read_queue(mem_address_t* uart_base_addr);



