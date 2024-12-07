/*
 * GPIO.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Hoang Viet
 */

#ifndef GPIO_H_
#define GPIO_H_
/******************************************************************************
 *  Defines
 *****************************************************************************/

#define GREEN_LED_ON      GPIOD->PCOR |= (1 << 5)
#define GREEN_LED_OFF     GPIOD->PSOR |= (1 << 5)
#define GREEN_LED_TOGGLE     GPIOD->PTOR |= (1 << 5)
#define RED_LED_ON    GPIOE->PCOR |= (1 << 29)
#define RED_LED_OFF   GPIOE->PSOR |= (1 << 29)
#define RED_LED_TOGGLE   GPIOE->PTOR |= (1 << 29)
#define SW1_STATUS (GPIOC->PDIR & 0x8)
#define SW2_STATUS (GPIOC->PDIR & 0x1000)
#define BUTTON_IS_PRESS (0)
#define DELAY_COUNT     1333UL


/******************************************************************************
 *  Function prototypes
 *****************************************************************************/
void initLed();
void delay_1ms();

#endif /* GPIO_H_ */
