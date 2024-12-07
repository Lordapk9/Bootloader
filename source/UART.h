/*
 * UART.h
 *
 *  Created on: Dec 24, 2023
 *      Author: Hoang Viet
 */

#ifndef UART_H_
#define UART_H_
/******************************************************************************
 *  Function prototypes
 *****************************************************************************/

void UART0_Init(unsigned int baudrate);
void SetBaurate(unsigned int baudrate);
void UART_SendChar (char c);
void UART_SendString(char *s);
void UART0_Denit();
void Clock_Denit();

#endif /* UART_H_ */
