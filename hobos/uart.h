#ifndef __UART_H
#define __UART_H

#include "chardev.h"
#include "gpio.h"
#include "uart.h"

extern uint64_t mmio_base;

/*
 * NOTE: This currently only implements mini UART - which is supported upto
 * RPI 4
 *
 * For RPI 5, PLL01 UART is needed, which is currently being worked on.
 * */

#define AUX_IO_BASE 	0x215000

#define AUX_ENABLES     0x04
#define AUX_MU_IO       0x40
#define AUX_MU_IER      0x44
#define AUX_MU_IIR      0x48
#define AUX_MU_LCR      0x4C
#define AUX_MU_MCR      0x50
#define AUX_MU_LSR      0x54
#define AUX_MU_MSR      0x58
#define AUX_MU_SCRATCH  0x5C
#define AUX_MU_CNTL     0x60
#define AUX_MU_STAT     0x64
#define AUX_MU_BAUD     0x68

//Clock assumed to be 250MHz for 115200 Baud
#define MINI_UART_BAUD 270

/*
 *
 * This is PL011 UART, supported by all RPI models.
 *
 */

#define RPI_LEGACY_UART0_BASE	0x20100
#define RPI_5_UART0_BASE	0x30000

#define PL011_LCRH_WLEN_8BIT	(3 << 5)  /* 8bit */

#define PL011_FR_RXFE (1 << 4)/* RX FIFO Empty */
#define PL011_FR_TXFF (1 << 5)/* TX FIFO full */

#define PL011_DR		0x00
#define PL011_FR		0x18
#define PL011_IBRD		0x24
#define PL011_FBRD		0x28
#define PL011_LCRH		0x2c
#define PL011_CR		0x30
#define PL011_CR_CTSEN		(1 << 15) /* CTS hardware flow control enable */
#define PL011_CR_RTSEN		(1 << 14) /* RTS hardware flow control enable */
#define PL011_CR_RTS		(1 << 11) /* Request to send */
#define PL011_CR_DTR		(1 << 10) /* Data transmit ready. */
#define PL011_CR_RXE		(1 << 9)  /* Receive enable */
#define PL011_CR_TXE		(1 << 8)  /* Transmit enable */
#define PL011_CR_LBE		(1 << 7)  /* Loopback enable */
#define PL011_CR_UARTEN		(1 << 0)  /* UART Enable */
#define PL011_IFLS		0x34
#define PL011_IMSC		0x38
#define PL011_RIS		0x3c
#define PL011_MIS		0x40
#define PL011_ICR		0x44
#define PL011_DMACR		0x48

#endif
