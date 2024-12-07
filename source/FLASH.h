/*
 * FLASH.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Hoang Viet
 */

#ifndef FLASH_H_
#define FLASH_H_

/******************************************************************************
 *  Function prototypes
 *****************************************************************************/

void Fls_EraseSector(uint32_t address);
void Fls_EraseMultiSector(uint32_t address, uint32_t numberSector);
void Fls_WriteLongWord(uint8_t* address, uint8_t data[]);
void Fls_Write(uint8_t* address, uint8_t data[], uint32_t numberByte);


#endif /* FLASH_H_ */
