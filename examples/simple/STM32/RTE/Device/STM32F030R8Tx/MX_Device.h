/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 06/01/2025 13:52:26
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            40000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            8000000
#define MX_HSE_VALUE                            8000000
#define MX_HSI14_VALUE                          14000000
#define MX_HSI48_VALUE                          48000000
#define MX_PLLCLKFreq_Value                     8000000
#define MX_PLLMCOFreq_Value                     4000000
#define MX_SYSCLKFreq_VALUE                     8000000
#define MX_HCLKFreq_Value                       8000000
#define MX_MCOFreq_Value                        8000000
#define MX_FCLKCortexFreq_Value                 8000000
#define MX_TimSysFreq_Value                     8000000
#define MX_AHBFreq_Value                        8000000
#define MX_APB1Freq_Value                       8000000
#define MX_APB1TimFreq_Value                    8000000
#define MX_ADCoutputFreq_Value                  14000000
#define MX_FLITFCLKFreq_Value                   8000000
#define MX_CECFreq_Value                        32786
#define MX_I2C1Freq_Value                       8000000
#define MX_I2SFreq_Value                        8000000
#define MX_USART1Freq_Value                     8000000
#define MX_USART2Freq_Value                     8000000
#define MX_RTCFreq_Value                        40000
#define MX_RTCHSEDivFreq_Value                  250000
#define MX_USBFreq_Value                        48000000
#define MX_WatchDogFreq_Value                   40000
#define MX_VCOOutput2Freq_Value                 4000000

/*-------------------------------- DMA        --------------------------------*/

#define MX_DMA                                  1

/* DMA Configuration */

/* DMA DMA1_Channel1 */
#define MX_DMA1_Channel1_DMA_DMA_Handle
#define MX_DMA1_Channel1_DMA_Instance           DMA1_Channel1
#define MX_DMA1_Channel1_DMA_Priority           DMA_PRIORITY_LOW
#define MX_DMA1_Channel1_DMA_PeriphDataAlignment DMA_PDATAALIGN_BYTE
#define MX_DMA1_Channel1_DMA_MemDataAlignment   DMA_MDATAALIGN_BYTE
#define MX_DMA1_Channel1_DMA_Mode               DMA_NORMAL
#define MX_DMA1_Channel1_DMA_Direction          DMA_MEMORY_TO_MEMORY
#define MX_DMA1_Channel1_DMA_PeriphInc          DMA_PINC_ENABLE
#define MX_DMA1_Channel1_DMA_MemInc             DMA_MINC_ENABLE
#define MX_DMA1_Channel1_DMA_IpInstance

/*-------------------------------- SPI1       --------------------------------*/

#define MX_SPI1                                 1

/* GPIO Configuration */

/* Pin PB4 */
#define MX_SPI1_MISO_GPIO_Speed                 GPIO_SPEED_FREQ_HIGH
#define MX_SPI1_MISO_Pin                        PB4
#define MX_SPI1_MISO_GPIOx                      GPIOB
#define MX_SPI1_MISO_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI1_MISO_GPIO_Pin                   GPIO_PIN_4
#define MX_SPI1_MISO_GPIO_AF                    GPIO_AF0_SPI1
#define MX_SPI1_MISO_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PB5 */
#define MX_SPI1_MOSI_GPIO_Speed                 GPIO_SPEED_FREQ_HIGH
#define MX_SPI1_MOSI_Pin                        PB5
#define MX_SPI1_MOSI_GPIOx                      GPIOB
#define MX_SPI1_MOSI_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI1_MOSI_GPIO_Pin                   GPIO_PIN_5
#define MX_SPI1_MOSI_GPIO_AF                    GPIO_AF0_SPI1
#define MX_SPI1_MOSI_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PB3 */
#define MX_SPI1_SCK_GPIO_Speed                  GPIO_SPEED_FREQ_HIGH
#define MX_SPI1_SCK_Pin                         PB3
#define MX_SPI1_SCK_GPIOx                       GPIOB
#define MX_SPI1_SCK_GPIO_PuPd                   GPIO_NOPULL
#define MX_SPI1_SCK_GPIO_Pin                    GPIO_PIN_3
#define MX_SPI1_SCK_GPIO_AF                     GPIO_AF0_SPI1
#define MX_SPI1_SCK_GPIO_Mode                   GPIO_MODE_AF_PP

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

/* Pin PB7 */
#define MX_PB7_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PB7_Pin                              PB7
#define MX_PB7_GPIOx                            GPIOB
#define MX_PB7_PinState                         GPIO_PIN_RESET
#define MX_PB7_GPIO_PuPd                        GPIO_NOPULL
#define MX_PB7_GPIO_Pin                         GPIO_PIN_7
#define MX_PB7_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP
#define MX_PB7_GPIO_FM7                         __NULL

/* Pin PB6 */
#define MX_PB6_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PB6_GPIO_FM6                         __NULL
#define MX_PB6_Pin                              PB6
#define MX_PB6_GPIOx                            GPIOB
#define MX_PB6_PinState                         GPIO_PIN_RESET
#define MX_PB6_GPIO_PuPd                        GPIO_NOPULL
#define MX_PB6_GPIO_Pin                         GPIO_PIN_6
#define MX_PB6_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

#endif  /* __MX_DEVICE_H */