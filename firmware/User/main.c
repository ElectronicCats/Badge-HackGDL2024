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
  * J-Link Connections: https://private-user-images.githubusercontent.com/44976441/277049150-2c44cddc-163c-4924-840f-2b99760bbca3.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MDc5NTA5NTYsIm5iZiI6MTcwNzk1MDY1NiwicGF0aCI6Ii80NDk3NjQ0MS8yNzcwNDkxNTAtMmM0NGNkZGMtMTYzYy00OTI0LTg0MGYtMmI5OTc2MGJiY2EzLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDAyMTQlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQwMjE0VDIyNDQxNlomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWYyODFkMTNjN2YyMDgyZTJhZmExYzc3MWI0M2YwYzBjZmRiZWYxYmJiMTY3NjE1ZDU5YmU3Njc3NThhMjAwOTUmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JmFjdG9yX2lkPTAma2V5X2lkPTAmcmVwb19pZD0wIn0.hkoYOHl2-wbGiy8-bgevjSikxN3sZxpCxZn3IUqJlPI
  * PUYA instructions: https://github.com/ElectronicCats/puya-projects
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

int message[] = {72,65,67,75,71,68,76,46};
enum puertos {
  B3=0x0001,
  B2=0x0002,
  B1=0x0040,
  B0=0x0080
};

void bitsSequence(int bit){
  if(bit==B3)
    HAL_GPIO_OnPin(GPIOF,bit);
  else
    HAL_GPIO_OnPin(GPIOA,bit);
}

void ASCII2HEX(){

}

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

//Sequence 8
void encryptedMessage(){
  
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
    //sequences(sequenceNumber);
    bitsSequence(B0);

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
