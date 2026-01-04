/**
 * @file gd32f303cb.h
 *
 */
/* Copyright (C) 2024 by Arjan van Vught mailto:info@gd32-dmx.org */

#ifndef BOARD_GD32F303CB_H_
#define BOARD_GD32F303CB_H_

#if !defined(BOARD_GD32F303CB)
# error This file should not be included
#endif

#if defined (MCU_GD32F30X_MCU_H_)
# error This file should be included later
#endif

#include <stdint.h>

/**
 * LED
 */

#define LED1_GPIO_PINx			GPIO_PIN_13
#define LED1_GPIOx				GPIOC
#define LED1_RCU_GPIOx			RCU_GPIOC

#define LED_BLINK_PIN			LED1_GPIO_PINx
#define LED_BLINK_GPIO_PORT		LED1_GPIOx
#define LED_BLINK_GPIO_CLK		LED1_RCU_GPIOx

/**
 * I2C
 */

#define I2C0_REMAP
#define I2C_REMAP				GPIO_I2C0_REMAP
#define I2C_PERIPH				I2C0_PERIPH
#define I2C_RCU_I2Cx			I2C0_RCU_I2C0
#define I2C_SCL_RCU_GPIOx		I2C0_SCL_RCU_GPIOx
#define I2C_SCL_GPIOx			I2C0_SCL_GPIOx
#define I2C_SCL_GPIO_PINx		I2C0_SCL_GPIO_PINx
#define I2C_SDA_RCU_GPIOx		I2C0_SDA_RCU_GPIOx
#define I2C_SDA_GPIOx			I2C0_SDA_GPIOx
#define I2C_SDA_GPIO_PINx		I2C0_SDA_GPIO_PINx

/**
 * SPI
 */

#define SPI_PERIPH				SPI1_PERIPH
#define SPI_RCU_SPIx			SPI1_RCU_SPI1
#define SPI_RCU_GPIOx			SPI1_RCU_GPIOx
#define SPI_GPIOx				SPI1_GPIOx
#define SPI_SCK_GPIO_PINx		SPI1_SCK_GPIO_PINx
#define SPI_MISO_GPIO_PINx		SPI1_MISO_GPIO_PINx
#define SPI_MOSI_GPIO_PINx		SPI1_MOSI_GPIO_PINx
#define SPI_NSS_RCU_GPIOx		SPI1_NSS_RCU_GPIOx
#define SPI_NSS_GPIOx			SPI1_NSS_GPIOx
#define SPI_NSS_GPIO_PINx		SPI1_NSS_GPIO_PINx
#define SPI_DMAx				SPI1_DMAx
#define SPI_DMA_CHx				SPI1_TX_DMA_CHx

/**
 * MCU and BOARD name
 */

#define GD32_MCU_NAME			"GD32F303CB"
#define GD32_BOARD_NAME			"GD32F303CB"

#include "mcu/gd32f30x_mcu.h"

#endif /* BOARD_GD32F303CB_H_ */
