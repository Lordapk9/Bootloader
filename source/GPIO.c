/*
 * GPIO.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Hoang Viet
 */
/******************************************************************************
 *  Includes
 *****************************************************************************/

#include "MKL46Z4.h"
#include "GPIO.h"

/******************************************************************************
 *  Global variables
 *****************************************************************************/



/******************************************************************************
 *  Function definitions
 *****************************************************************************/

void initLed()
{
    /* Enable clock for PORTD, PORTE */
    SIM->SCGC5 |= (1 << 12);    /* Set bit 12 */
    SIM->SCGC5 |= (1 << 13);    /* Set bit 13 */
    SIM->SCGC5 |= (1 << 11);    /* Set bit 11 */

    /* Configure multiplex of PTD5 and PTE29 as GPIO */
    PORTD->PCR[5] |= PORT_PCR_MUX(1);
    PORTE->PCR[29] |= PORT_PCR_MUX(1);
    PORTC->PCR[3] |= PORT_PCR_MUX(1);
    PORTC->PCR[3] |= 3;
    PORTC->PCR[3] |= PORT_PCR_IRQC(10);

    /* Configure PTD5 and PTE29 as output */
    GPIOD->PDDR |= (1 << 5);
    GPIOE->PDDR |= (1 << 29);
    GPIOC->PDDR &= ~(1 << 3);

    /* Clear PTD5 and PTE29 */
    RED_LED_ON;
    GREEN_LED_ON;

}

void delay_1ms(uint32_t time)
{
    unsigned long i;

    for (i = 0; i < DELAY_COUNT*time; i++)
    {
        __asm("nop");
    }
}
