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
#include <stdint.h>

/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void APP_LedConfig(void);
uint16_t delay1 = 300, interimPeriod = 1000;
uint8_t delay = 150, delay2 = 250, delay3 = 250;
uint8_t times = 0, init = 0, timesSequences = 14, timesSecretCode = 4, sequenceNumber = 1;

uint32_t ports[] = {GPIOF, GPIOA, GPIOA, GPIOA};
uint8_t pins[] = {0x0001, 0x0002, 0x0040, 0x0080};

char message[] = {"HACKGDL"};

void setBits(uint8_t nibble)
{
  uint8_t nibbleAux = nibble;
  for (uint8_t i = 0; i < 4; i++)
  {
    if (nibbleAux & 0x01) // LED ON
    {
      HAL_GPIO_OnPin(ports[i], pins[i]);
    }
    else
    {
      HAL_GPIO_OffPin(ports[i], pins[i]);
    }
    nibbleAux = nibble >> i + 1;
  }
  HAL_Delay(1000);
}

void HEX2NIBBLE()
{
  uint8_t nibble1, nibble2;
  for (uint8_t i = 0; i < sizeof(message) - 1; i++)
  {
    nibble1 = message[i] & 0x0F;
    nibble2 = message[i] >> 4;
    setBits(nibble1);
    setBits(nibble2);
  }
}

// Sequence 1
void circleSequence()
{
  // HAL_Delay(delay);
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); // Start with PF0 ON
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
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7); // Turn off PA7
  // Return
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); // Start with PF0
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

// Sequence 2
void crossSequence()
{
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); // Start with PF0
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
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7); // Turn off PA7
  HAL_Delay(delay);
}

// Using 2 LEDs at same time
// Seqeuence 3
void crossSequence2()
{
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); // Start with PF0
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6); // Start with PA6
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1); // Turn down PA1
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7); // Turn down PA7
}
// Seqeuence 4

void continuosCircleSequence()
{
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); // Start with PF0
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1); // Start with PA6
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6); // Turn down PA1
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);
}

// Using many LEDs
// Seqeuence 5
void fullCircleSequence()
{
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); // 1
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1); // 12
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6); // 123
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7); // 1234
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7); // 123
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6); // 12
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1); // 1
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0); // 0
  HAL_Delay(delay2);
  // return sequence
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); // 0
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay2);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1); // return
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);
  HAL_Delay(delay2);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0); // 0
  HAL_Delay(delay2);
}

// Seqeuence 6
void loadingSequence()
{
  if (init == 0)
  {
    startSequence();
    init = 1;
  }
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6); // 123
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0); // Turn off PF0
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);  // 234
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1); // Turn off PA1
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);  // 341
  HAL_Delay(delay);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6); // Turn off PA6
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);  // 412
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

// Seqeuence 7
void blinkSequence()
{
  ledsOn();
  HAL_Delay(delay1);
  ledsOff();
  HAL_Delay(delay1);
}

void startSequence()
{
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0); // 1
  HAL_Delay(delay);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1); // 12
  HAL_Delay(delay);
}

// This sequence maybe need to be deleted
void ledsOff()
{
  HAL_GPIO_OffPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_1);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OffPin(GPIOA, GPIO_PIN_7);
}

void ledsOn()
{
  HAL_GPIO_OnPin(GPIOF, GPIO_PIN_0);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_1);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_6);
  HAL_GPIO_OnPin(GPIOA, GPIO_PIN_7);
}

void checkTimes()
{
  times += 1;
  if (times == 4)
  {
    sequenceNumber += 1;
    times = 0;
  }
}

void sequences(int sequence)
{
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
    blinkSequence();
    blinkSequence();
    checkTimes();
    break;
  default:
    ledsOn();
    sequenceNumber = 1;
    HAL_Delay(1000);
    break;
  }
}

int main(void)
{
  HAL_Init();

  APP_LedConfig();

  BSP_USART_Config();

  for (uint8_t c = 1; c < 7; c++)
  {
    sequences(c);
  }

  for (uint8_t c2 = 0; c2 < timesSecretCode; c2++)
  {
    sequences(7); //Blink Sequence 3 times
    ledsOff();
    HAL_Delay(interimPeriod);
    HEX2NIBBLE();
    ledsOff();
    HAL_Delay(interimPeriod);
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
  while (1)
    ;
}

#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
