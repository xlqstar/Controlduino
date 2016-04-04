/**
 * Copyright (c) 2015 by Mylife1213 <mylife1213@gmail.com>
 * Nrf24l01P library for Arduino.
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 * version v1.0
 **/


#ifndef nrf_base_H_ 
#define nrf_base_H_

#include "Arduino.h"
#include "nrf_api.h"


#define uint8_t uint8_t

class nrf_base 
{
  public:     
      
        uint8_t _CE;
        uint8_t _CSN; 
        uint8_t _CLK;
        uint8_t _MOSI;
        uint8_t _MISO; 
       
     nrf_base(uint8_t CE,uint8_t CSN);
     nrf_base(uint8_t CE,uint8_t CSN,uint8_t CLK, uint8_t MOSI,uint8_t MISO);        

        uint8_t RW(uint8_t byte_1);
        uint8_t RW_Reg(uint8_t reg,uint8_t value);
        uint8_t Read(uint8_t reg);

        uint8_t Read_Buf(uint8_t reg ,uint8_t *pBuf, uint8_t bytes);

        uint8_t Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t bytes);
               
  private:      
        uint8_t _soft_spi;
     

};

#endif