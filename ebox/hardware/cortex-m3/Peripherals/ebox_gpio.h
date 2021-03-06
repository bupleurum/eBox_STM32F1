/**
  ******************************************************************************
  * @file    gpio.h
  * @author  shentq
  * @version V2.1
  * @date    2016/08/14
  * @brief   
  ******************************************************************************
  * @attention
  *
  * No part of this software may be used for any commercial activities by any form 
  * or means, without the prior written consent of shentq. This specification is 
  * preliminary and is subject to change at any time without notice. shentq assumes
  * no responsibility for any errors contained herein.
  * <h2><center>&copy; Copyright 2015 shentq. All Rights Reserved.</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __GPIO_H
#define __GPIO_H
#include "ebox_core.h"
#include "mcu_config.h"

class mcuGpio :public Gpio
{
public:
    mcuGpio(GPIO_TypeDef *port, uint16_t pin);
    virtual void mode(PIN_MODE mode);
    virtual void set();
    virtual void reset();
    virtual void write(uint8_t val);
    virtual void toggle();
    virtual void read(uint8_t *val);
    virtual uint8_t read(void);

    operator int();
    int operator =(mcuGpio&);
    mcuGpio operator = (int value);

public:
    GPIO_TypeDef *port; /**< 引脚的端口 */
    uint16_t pin; /**< 引脚的序号 */
};


#endif
