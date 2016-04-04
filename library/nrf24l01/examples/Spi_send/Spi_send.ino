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

uint8_t tx_addr[] = { 0x03, 0xFF, 0xFF, 0xFF, 0xFF};//发送地址
uint8_t tx_data[32]={1,2,3,4};//发送的数据，32位

void setup() {
  nrf.send_mode(tx_addr);//设置为发送模式，参数为发送地址
}

void loop() {
  
  tx_data[0]++;
  nrf.send(tx_addr,tx_data);//发送数据，参数:发送地址，数据
  delay(5000);

}







