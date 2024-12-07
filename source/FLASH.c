/*
 * FLASH.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Hoang Viet
 */

/******************************************************************************
 *  Includes
 *****************************************************************************/

#include "MKL46Z4.h"
#include "FLASH.h"



/******************************************************************************
 *  Global variables
 *****************************************************************************/



/******************************************************************************
 *  Function definitions
 *****************************************************************************/

void Fls_EraseSector(uint32_t address)
{
	while(((FTFA->FSTAT) & FTFA_FSTAT_CCIF_MASK) == 0);
	FTFA->FCCOB0 = 0x09;
	FTFA->FCCOB3 = address & 0xFF;
	FTFA->FCCOB2 = (address & 0xFF00) >> 8;
	FTFA->FCCOB1 = (address & 0xFF0000) >> 16;
	FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;
	while(((FTFA->FSTAT) & FTFA_FSTAT_CCIF_MASK) == 0);


}
void Fls_EraseMultiSector(uint32_t address, uint32_t number){
	uint32_t i;
	for(i=0;i < number;i++)
	{
		Fls_EraseSector(address+(i*1024));
	}

}
void Fls_WriteLongWord(uint8_t* address, uint8_t data[])
{
	while(((FTFA->FSTAT) & FTFA_FSTAT_CCIF_MASK) == 0);//wait for flash free
	FTFA->FCCOB0 = 0x06;
	FTFA->FCCOB3 = address[1];
	FTFA->FCCOB2 = address[0];
	FTFA->FCCOB1 = 0;

	FTFA->FCCOB7 = data[0];
	FTFA->FCCOB6 = data[1];
	FTFA->FCCOB5 = data[2];
	FTFA->FCCOB4 = data[3];
	FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;
	while(((FTFA->FSTAT) & FTFA_FSTAT_CCIF_MASK) == 0);
}

void Fls_Write(uint8_t* address, uint8_t* data, uint32_t numberByte)
{
	    uint32_t i =0;
		while(i < (numberByte/4))
		{
			Fls_WriteLongWord(address, &data[i*4]);
			address[1] +=4;
			i++;
		}

}


