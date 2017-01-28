/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Glenn Ruben Bakke
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef HAL_TWI_H__
#define HAL_TWI_H__

#include "nrf.h"

#define TWI_BASE_POINTERS (const uint32_t[]){NRF_TWI0_BASE, NRF_TWI1_BASE}
#define TWI_BASE(x) ((NRF_TWI_Type *)TWI_BASE_POINTERS[x])

#if NRF51

#define TWI_IRQ_VALUES (const uint32_t[]){SPI0_TWI0_IRQn, SPI1_TWI1_IRQn}

#elif NRF52

#define TWI_IRQ_VALUES (const uint32_t[]){SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQn, \
                                          SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1_IRQn}

#endif

#if NRF52

/**
  * @brief  TWIM Configuration Structure definition
  */
typedef struct {
} hal_twim_init_t;

/**
  * @brief  TWIS Configuration Structure definition
  */
typedef struct {
} hal_twis_init_t;

#endif

/**
  * @brief  TWI clock frequency type definition
  */
typedef enum {
    HAL_TWI_FREQ_100_Kbps = 0,
    HAL_TWI_FREQ_250_Kbps,
    HAL_TWI_FREQ_400_Kbps
} hal_twi_clk_freq_t;

/**
  * @brief  TWI role type definition
  */
typedef enum {
    HAL_TWI_MASTER,
    HAL_TWI_SLAVE
} hal_twi_role_t;

/**
  * @brief  TWI Configuration Structure definition
  */
typedef struct {
    uint8_t             id;           /* TWI instance id */
    hal_twi_role_t      role;         /* TWI master/slave */
    hal_twi_clk_freq_t  freq;         /* TWI frequency */
} hal_twi_init_t;

/**
  * @brief  TWI handle Structure definition
  */
typedef struct __TWI_HandleTypeDef
{
    NRF_TWI_Type        *instance;    /* TWI register base address */
    hal_twi_init_t      init;         /* TWI initialization parameters */
} TWI_HandleTypeDef;

void hal_twi_init(NRF_TWI_Type * p_instance, hal_twi_init_t const * p_twi_init);

#endif // HAL_TWI_H__
