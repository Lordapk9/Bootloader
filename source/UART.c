/*
 * UART.c
 *
 *  Created on: Dec 24, 2023
 *      Author: Hoang Viet
 */

/******************************************************************************
 *  Includes
 *****************************************************************************/

#include "MKL46Z4.h"
#include "UART.h"

/******************************************************************************
 *  Global variables
 *****************************************************************************/



/******************************************************************************
 *  Function definitions
 *****************************************************************************/

void UART0_Init(unsigned int baudrate)
{
		/* Configure the UART clock */
	    SIM->SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
	    SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);

	    /*Pin configuration A1 RX A2 TX*/
	    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	    PORTA->PCR[1] &= ~ PORT_PCR_MUX_MASK;
	    PORTA->PCR[1] |= PORT_PCR_MUX(2);
	    PORTA->PCR[2] &= ~ PORT_PCR_MUX_MASK;
	    PORTA->PCR[2] |= PORT_PCR_MUX(2);

	    /* Configure UART parameters */
	    SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
	    UART0->C1 &= ~UART_C1_M_MASK; /* 8 bit mode */
	    UART0->C1 &= ~UART_C1_PE_MASK; /* none parity */
	    UART0->BDH &= ~ UART_BDH_SBNS_MASK; /* 1 bit stop */
	    SetBaurate(baudrate);
	    UART0->C2 |= UART_C2_RIE_MASK;
	    NVIC_EnableIRQ(UART0_IRQn); /* Enable Ngắt */
}

void SetBaurate(unsigned int baudrate)
{
	unsigned int temp = 21000000 / baudrate;
	unsigned int baudrate_max = 21000000 / 4;
	unsigned int OSR_optimize = 16;
	unsigned int SBR_optimize = temp / (OSR_optimize +1);
	unsigned int SBR_tempH, SBR_tempL, SBR_temp;
	unsigned int delta_optimize, delta_tempH, delta_tempL, delta_temp;
	unsigned int i;
	if(baudrate > baudrate_max)
	{
		UART_SendString("Gia tri baudrate qua lon\n");
	} else
	{
		delta_optimize = 0xFFFFFFFF;
		for(i = 3; i < 32; i++)
		{
			SBR_tempL = temp / (i + 1);
			SBR_tempH = (temp / (i + 1)) + 1;
			delta_tempL = (21000000/((i + 1) * SBR_tempL)) - baudrate;
			delta_tempH = baudrate - (21000000/((i + 1) * SBR_tempH));

			if(delta_tempL < delta_tempH)
			{
				delta_temp = delta_tempL;
				SBR_temp = SBR_tempL;
			} else
			{
				delta_temp = delta_tempH;
				SBR_temp = SBR_tempH;
			}

			if(delta_temp <= delta_optimize)
			{
				OSR_optimize = i;
				SBR_optimize = SBR_temp;
				delta_optimize = delta_temp;
			}
		}
	    UART0->C2 &= ~UART_C2_TE_MASK;
		UART0->C2 &= ~UART0_C2_RE_MASK;
		UART0->C4 = OSR_optimize;

		UART0->BDL = UART0_BDL_SBR(SBR_optimize & UART0_BDL_SBR_MASK);
		UART0->BDH &= ~UART0_BDH_SBR_MASK;
		UART0->BDH |= UART0_BDH_SBR(SBR_optimize >> 8);

	    UART0->C2 |= UART_C2_TE_MASK;
		UART0->C2 |= UART0_C2_RE_MASK;
	}
}

void UART_SendChar (char c)
{
	UART0->D = c;
	while(((UART0->S1)&UART_S1_TDRE_MASK) != UART_S1_TDRE_MASK);

}


void UART_SendString(char *s)
{
  unsigned int index = 0;
  while (s[index] != '\0')
  {
    UART_SendChar(s[index]);
    index++;
  }

}

void UART0_Denit()
{
		NVIC_DisableIRQ(UART0_IRQn);
	    UART0->C2 &= ~UART0_C2_TE_MASK;
	    UART0->C2 &= ~UART0_C2_RE_MASK;
	    UART0->C1 &= ~UART_C1_M_MASK;
	    UART0->C1 &= ~UART_C1_PE_MASK;
	    UART0->BDH &= ~UART_BDH_SBNS_MASK;
}
void Clock_Denit()
{
	    SIM->SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
}
