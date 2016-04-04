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
     ����������ʹ��Ӳ��spi
    **/
    Multiple(uint8_t ce, uint8_t csn);
    /**
     ����������ʹ��SOFT SPI
     **/
    Multiple(uint8_t ce, uint8_t csn,uint8_t clk,uint8_t mosi,uint8_t miso);
     /**
     ���óɶ�ȡģʽ������: p1��������ַ��p2_p5������յ�ַ��λ
     **/
     uint8_t read_mode(uint8_t* p1, uint8_t* p2_p5);
     /**
      ����ʹ���ж�ģʽ
      **/
     void Interrup(uint8_t pin,void (*func)() );
     /**
      �ж�ģʽ�µĽ������ݶ�ȡ��channelͨ����data��ȡ������
     **/
     uint8_t Interrup_read(uint8_t channel,uint8_t* data);
     /**
      ��ͨģʽ�µ����ݶ�ȡ��channelͨ����data��������
      ����ֵ 1���յ�����  0��û������
      **/
     uint8_t read(uint8_t channel,uint8_t* data);
     /**
      ���÷���ģʽ,����p0�����͵ĵ�ַ����
      **/
     uint8_t send_mode(uint8_t* p0);
     /**
      �������ݣ�addr�����͵�ַ  data:������������
      **/
     uint8_t send(uint8_t* addr, uint8_t* data);
     /**
      ���ù��ܣ�reg������ data����ֵ
     **
     *
     "Mode"-> "Receive" or "Send" //ģʽ
     "Power"-> "up" or "Down"     //��Դģʽ
     "CRC"-> "16bit" or "8bit"   //CRCУ��ģʽ
     "RF_Power"->"0dBm"or"-6dBm"or"-12dBm"or"-18dBm"  //����
     "Rate"->"1M"or"2M"or"250k"   //����
     "RF_Channel"->��ֵ    //�ŵ�
     *
     **/
     int set_reg(String reg, String data);
     
     /** 
      �Ĵ������Ա�����������ģʽǰ����
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