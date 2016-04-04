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
**/ 


#include"Multiple.h"

Multiple nrf(9,8);//构建函数，参数分别为CE,CSN

uint8_t rx_addr_p1[6]={ 0x01, 0xFF, 0xFF, 0xFF, 0xFF};//接收地址
uint8_t rx_addr_p2_5[6]={0x02,0x03,0x04,0x05}; /**
                                              通道2至5地址，各地址=各个数
                                              组元素+rx_addr_p1后4位**/

uint8_t rx_data[32];//接收数据存储
uint8_t channel;//接收通道
uint8_t tmp;

void setup() {
  Serial.begin(9600);
  nrf.read_mode(rx_addr_p1, rx_addr_p2_5);//设置为接收模式，参数：通道1地址，通道2-5地址

}

void loop() { 
   
   
   
   tmp=nrf.read(channel,rx_data);//读取接收数据，有数据返回1,参数：通道，数据
   if(tmp==1)
   {
     Serial.print("Channel= ");
     Serial.print(channel);
     Serial.print(" rx_data[0]= ");
     Serial.println(rx_data[0]);
   }
  
}







