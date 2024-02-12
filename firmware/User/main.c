/**
  ******************************************************************************
  * @file    main.c
  * @author  MCU Application Team
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "py32f0xx_bsp_printf.h"

/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void APP_LedConfig(void);
int delay=150, delay1=300, delay2=250, delay3=250;
int times=0, init=0;
int sequenceNumber = 1;

//Sequence 1
void circleSequence(){
  //HAL_Delay(delay);     
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); //Start with PF0 ON
  HAL_Delay(delay);     
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);                     
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7); //Turn off PA7
  //Return
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); //Start with PF0
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0); 
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7); 
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6); 
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);
  HAL_Delay(delay);
}

//Sequence 2
void crossSequence(){
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); //Start with PF0
  HAL_Delay(delay);     
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);                     
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7); //Turn off PA7
  HAL_Delay(delay);
}

//Using 2 LEDs at same time
//Seqeuence 3
void crossSequence2(){
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);  //Start with PF0                  
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);  //Start with PA6
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);  //Turn down PA1
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);  //Turn down PA7
}
//Seqeuence 4

void continuosCircleSequence(){
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);  //Start with PF0                  
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);  //Start with PA6
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);  //Turn down PA1
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);
}

//Using many LEDs
//Seqeuence 5
void fullCircleSequence(){
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);  //1
  HAL_Delay(delay2);       
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);  //12
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);  //123
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);  //1234
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);  //123
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6); //12
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1); //1
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);  //0
  HAL_Delay(delay2);
  //return sequence
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);  //0
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);  
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);  //return
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);  //0
  HAL_Delay(delay2);
}

//Seqeuence 6
void loadingSequence(){
  if (init==0)
  {
    startSequence();
    init=1;
  }
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);  
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);  //123
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);  //Turn off PF0
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);  //234
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);  //Turn off PA1
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);  //341
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);  //Turn off PA6
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);  //412
  HAL_Delay(delay);
  /*
  //return sequence
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay2);
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay2);
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);  
  HAL_Delay(delay2);
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);  //return
  HAL_Delay(delay2);
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay2);
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay2);
  */
}

//Seqeuence 7
void blinkSequence(){
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);                           
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay1);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);                           
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay1);
}

void startSequence(){
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);  //1
  HAL_Delay(delay);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);  //12
  HAL_Delay(delay);
}
//This sequence maybe need to be deleted
void ledsOff(){
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);                           
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);
}

void ledsOn(){
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);                           
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
}
void checkTimes(){
  times+=1;
    if(times==4){
      sequenceNumber+=1;
      times=0;
      }
}

void sequences(int sequence){
  switch (sequence)
  {
  case 1:
    circleSequence();
    checkTimes();
    break;
  case 2:
    crossSequence();
    checkTimes();
    break;
  case 3:
    crossSequence2();
    checkTimes();
    break;
  case 4:
    continuosCircleSequence();
    checkTimes();
    break;
  case 5:
    fullCircleSequence();
    checkTimes();
    break;
  case 6:
    loadingSequence();
    checkTimes();
    break;
  case 7:
    blinkSequence();
    checkTimes();
    break;
  default:
    ledsOn();
    sequenceNumber=1;
    break;
  }
}

int main(void)
{
  HAL_Init();                                 
  
  APP_LedConfig();

  BSP_USART_Config();

  //printf("\r\nPY32F0xx LED Toggle Demo\r\nSystem Clock: %ld\r\n", SystemCoreClock);
  while (1)
  {
    sequences(sequenceNumber);

    static uint32_t cnt = 0;
    printf("Hello world: %u\r\n", cnt++);
  }
}

static void APP_LedConfig(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  __HAL_RCC_GPIOF_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}

void APP_ErrorHandler(void)
{
  while (1);
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
