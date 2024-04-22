/**
  * @brief Interrupt Callback Definition for GPIO EXTI
  * @param None
  * @retval None
*/
#include "stm32f0xx_hal.h"
#include "sensor.h"
#include "main.h"

#define DIRECTION 1
/*
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == GPIO_PIN_5) { // GPIO_PIN_5 =  AR Right Wheel

    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == GPIO_PIN_SET) { // PA6 = BR Right Wheel
      //Increment encoder count
      rightEncoderCount += DIRECTION;
    } else {
      //Decrement encoder count
      rightEncoderCount -= DIRECTION;
  }

  } else if(GPIO_Pin == GPIO_PIN_13) { // GPIO_PIN_13 = AL Left Wheel
    
    if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14) == GPIO_PIN_SET) { // PB14 = BL Left Wheel
      //Increment encoder count
      leftEncoderCount += DIRECTION;
    } else {
      //Decrement encoder count
      leftEncoderCount -= DIRECTION;
    }

  } else {
      __NOP();
  }
}
*/
/// @brief Function to convert encoder count to rpm
/// @param encoderCount: 
/// @param Pin_B: GPIO Pin for Output B of Encoder
uint16_t encoderToRpm(uint16_t encoderCount, uint16_t interval) {
  uint16_t rpm = 0;
  //Calculate RPM
  rpm = (encoderCount * 60 * 1000) / (ENCODER_COUNT_PER_REV * interval);
  return rpm;
}

