/**
 * Copyright (c) 2015 by Mylife1213 <mylife1213@gmail.com>
 * Nrf24l01P library for Arduino.
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 * version v1.0
 **/
 
  /**
 nrf24l01   arduino
 csk->      csk
 mosi->     mosi
 miso->     miso
 ce->      用户设置    
 csn->     用户设置
 isr->     用户设置中断引脚
**/ 


#include"Multiple.h"

Multiple nrf(9,8);//构建函数，参数分别为CE,CSN

uint8_t rx_addr_p1[6]={ 0x01, 0xFF, 0xFF, 0xFF, 0xFF};//接收地址
uint8_t rx_addr_p2_5[6]={0x02,0x03,0x04,0x05}; /**
                                              通道2至5地址，各地址=各个数
                                              组元素+rx_addr_p1后4位**/

uint8_t rx_data[32];//接收数据存储
uint8_t channel;//接收通道

void setup() {
  Serial.begin(9600);
  nrf.read_mode(rx_addr_p1, rx_addr_p2_5);//设置为接收模式，参数：通道1地址，通道2-5地址
  nrf.Interrup(0, r_data);//设置为中断接收，参数：中断号，中断函数
}

void loop() { 

}

void r_data()
{
  nrf.Interrup_read(channel, rx_data);//中断模式下读取数据，参数:通道，接收数据
  Serial.print("Channel: ");
  Serial.print(channel);
  Serial.print("rx_data[0]=");
  Serial.println(rx_data[0]);
}





