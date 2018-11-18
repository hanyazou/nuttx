/****************************************************************************
 * configs/nrf52-generic/src/nrf52_userleds.c
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Author:  Janne Rosberg <janne@offcode.fi>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>
#include <debug.h>

#include <arch/board/board.h>

#include "chip.h"
#include "up_arch.h"
#include "up_internal.h"

#include "nrf52-generic.h"

#ifndef CONFIG_ARCH_LEDS

#ifdef CONFIG_NRF52_GENERIC_LED_ACTIVELOW
#define LED_ON 0
#define LED_OFF 1
#else
#define LED_ON 1
#define LED_OFF 0
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* LED definitions **********************************************************/
/*
 * If CONFIG_ARCH_LEDS is not defined, then the LEDs are completely under
 * control of the application.  The following interfaces are then available
 * for application control of the LEDs:
 *
 *  void board_userled_initialize(void);
 *  void board_userled(int led, bool ledon);
 *  void board_userled_all(uint8_t ledset);
 */

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: led_dumppins
 ****************************************************************************/

#ifdef LED_VERBOSE
static void led_dumppins(FAR const char *msg)
{
  nrf52_pin_dump(PINCONFIG_LED, msg);
  nrf52_gpio_dump(GPIO_LED, msg);
}
#else
#  define led_dumppins(m)
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_userled_initialize
 ****************************************************************************/

void board_userled_initialize(void)
{
  /* Configure LED pin as a GPIO outputs */

  led_dumppins("board_userled_initialize() Entry)");

  /* Configure GPIO as an outputs */

#if 0 < BOARD_NLEDS
  nrf52_gpio_config(GPIO_LED1);
#endif
#if 1 < BOARD_NLEDS
  nrf52_gpio_config(GPIO_LED2);
#endif
#if 2 < BOARD_NLEDS
  nrf52_gpio_config(GPIO_LED3);
#endif
#if 3 < BOARD_NLEDS
  nrf52_gpio_config(GPIO_LED4);
#endif

  led_dumppins("board_userled_initialize() Exit");
}

/****************************************************************************
 * Name: board_userled
 ****************************************************************************/

void board_userled(int led, bool ledon)
{
#if 0 < BOARD_NLEDS
  if (led == BOARD_LED1) {
    nrf52_gpio_write(GPIO_LED1, ledon ? LED_ON : LED_OFF);
  }
#endif
#if 1 < BOARD_NLEDS
  if (led == BOARD_LED2) {
      nrf52_gpio_write(GPIO_LED2, ledon ? LED_ON : LED_OFF);
  }
#endif
#if 2 < BOARD_NLEDS
  if (led == BOARD_LED3) {
      nrf52_gpio_write(GPIO_LED3, ledon ? LED_ON : LED_OFF);
  }
#endif
#if 3 < BOARD_NLEDS
  if (led == BOARD_LED4) {
      nrf52_gpio_write(GPIO_LED4, ledon ? LED_ON : LED_OFF);
  }
#endif
}

/****************************************************************************
 * Name: board_userled_all
 ****************************************************************************/

void board_userled_all(uint8_t ledset)
{
#if 0 < BOARD_NLEDS
  nrf52_gpio_write(GPIO_LED1, (ledset & BOARD_LED1_BIT) ? LED_ON : LED_OFF);
#endif
#if 1 < BOARD_NLEDS
  nrf52_gpio_write(GPIO_LED2, (ledset & BOARD_LED2_BIT) ? LED_ON : LED_OFF);
#endif
#if 2 < BOARD_NLEDS
  nrf52_gpio_write(GPIO_LED3, (ledset & BOARD_LED3_BIT) ? LED_ON : LED_OFF);
#endif
#if 3 < BOARD_NLEDS
  nrf52_gpio_write(GPIO_LED4, (ledset & BOARD_LED4_BIT) ? LED_ON : LED_OFF);
#endif
}

#endif /* !CONFIG_ARCH_LEDS */
