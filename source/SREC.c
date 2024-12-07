/*
 * SREC.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Hoang Viet
 */
/******************************************************************************
 *  Includes
 *****************************************************************************/

#include "MKL46Z4.h"
#include "SREC.h"
#include "stdbool.h"
#include "UART.h"
/******************************************************************************
 *  Global variables
 *****************************************************************************/



/******************************************************************************
 *  Function definitions
 *****************************************************************************/

uint8_t add_lenght(char type)
{
	int result = 0;
	 if ( type == '1' || type == '9')
	    {
	        result = 4;
	    }
	    else if (type == '2' || type == '8')
	    {
	    	result = 6;
	    }
	    else if (type == '3' || type == '7')
	    {
	    	result = 8;
	    }else if( type == '0' )
	    {
	    	result = 4;
	    }
	 return result;
}

int TwoChar_toByte(char chuc, char donvi)
{
	int sum;
	sum = 0;
	if(chuc >= 'A' && chuc <= 'Z')
	{
		chuc = (chuc - 'A' + 10);
	} else if(chuc >= '0' && chuc <= '9')
	{
		chuc = chuc - '0';
	}
	if(donvi >= 'A' && donvi <= 'Z')
	{
		donvi = donvi - 'A' + 10;
	}
	else if (donvi >= '0' && donvi <= '9')
	{
		donvi = donvi - '0';
	}
	sum = (chuc << 4) + donvi;
	return sum;
}

void Check_sum(uint32_t *line)
{
	int legnht;
	int i;
	int sum;
	int check;
	bool flag = true;
//	uint8_t *line = (uint8_t*)Get_Current_Read_Idx();
	legnht = (line[2]*16 + line[3]*1)*2 + 4;
	for(i = 0; i < legnht; i++)
	{
		sum =  TwoChar_toByte(line[i], line[i+1]);
	}
	check = ~sum & (0xFF);
	if( check != 0 )
	{
		flag = false;
		UART_SendString("File Srec bi loi, vui long cap nhat lai");
	}


}

