/**
 * Copyright (c) 2015 by Mylife1213 <mylife1213@gmail.com>
 * Nrf24l01P library for Arduino.
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 * version v1.1
 **/



#ifndef Multiple_H_ 
#define Multiple_H_

#include "nrf_base.h"
#include "string.h"

#define uint8_t unsigned char

class Multiple : public nrf_base
{
public:
    /**
     构建函数，使用硬件spi
    **/
    Multiple(uint8_t ce, uint8_t csn);
    /**
     构建函数，使用SOFT SPI
     **/
    Multiple(uint8_t ce, uint8_t csn,uint8_t clk,uint8_t mosi,uint8_t miso);
     /**
     设置成读取模式，参数: p1接收主地址，p2_p5其余接收地址首位
     **/
     uint8_t read_mode(uint8_t* p1, uint8_t* p2_p5);
     /**
      设置使用中断模式
      **/
     void Interrup(uint8_t pin,void (*func)() );
     /**
      中断模式下的接收数据读取，channel通道，data读取的数组
     **/
     uint8_t Interrup_read(uint8_t channel,uint8_t* data);
     /**
      普通模式下的数据读取，channel通道，data数据数组
      返回值 1：收到数据  0：没有数据
      **/
     uint8_t read(uint8_t channel,uint8_t* data);
     /**
      设置发送模式,参数p0：发送的地址数组
      **/
     uint8_t send_mode(uint8_t* p0);
     /**
      发送数据，addr：发送地址  data:发送数据数组
      **/
     uint8_t send(uint8_t* addr, uint8_t* data);
     /**
      配置功能，reg：功能 data：数值
     **
     *
     "Mode"-> "Receive" or "Send" //模式
     "Power"-> "up" or "Down"     //电源模式
     "CRC"-> "16bit" or "8bit"   //CRC校验模式
     "RF_Power"->"0dBm"or"-6dBm"or"-12dBm"or"-18dBm"  //功率
     "Rate"->"1M"or"2M"or"250k"   //速率
     "RF_Channel"->数值    //信道
     *
     **/
     int set_reg(String reg, String data);
     
     /** 
      寄存器调试变量，需设置模式前启用
      **/

      uint8_t _EN_AA;
      uint8_t _EN_RXADDR;
      uint8_t _SETUP_RETR;
      uint8_t _RF_CH;
      uint8_t _RF_SETUP;
      uint8_t _SETUP_AW;
      uint8_t _CONFIG;
      uint8_t _RX_PW;

      uint8_t _TX_EN_AA;
      uint8_t _TX_EN_RXADDR;
      uint8_t _TX_SETUP_RETR;
      uint8_t _TX_RF_CH;
      uint8_t _TX_RF_SETUP;
      uint8_t _TX_SETUP_AW;
      uint8_t _TX_CONFIG;
      uint8_t _TX_PW;


private:
  
};


#endif