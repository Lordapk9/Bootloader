/*
 * SREC.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Hoang Viet
 */

#ifndef SREC_H_
#define SREC_H_

/******************************************************************************
 *  Function prototypes
 *****************************************************************************/

int TwoChar_toByte(char chuc, char donvi);
uint8_t add_lenght(char type);
void Check_sum(uint32_t *line);
#endif /* SREC_H_ */
