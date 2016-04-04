/**
 * Copyright (c) 2015 by Mylife1213 <mylife1213@gmail.com>
 * Nrf24l01P library for Arduino.
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 * version v1.0
 **/

#include <nrf_base.h>


nrf_base::nrf_base(uint8_t CE,uint8_t CSN)
{
          
            _CE=CE;
            _CSN=CSN;
            pinMode(MISO,INPUT);
            pinMode(MOSI,OUTPUT);
            pinMode(SCK,OUTPUT);
            pinMode(SS,OUTPUT);
            SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); 
            pinMode(CE,OUTPUT);
            pinMode(CSN,OUTPUT);
            digitalWrite(CE,LOW);
}

nrf_base::nrf_base(uint8_t CE,uint8_t CSN,uint8_t CLK, uint8_t MOSI,uint8_t MISO)
{
  //SOFT SPI
  _CE=CE; _CSN=CSN; _CLK=CLK; _MOSI=MOSI; _MISO=MISO;

 pinMode(_CE,OUTPUT); pinMode(_CSN,OUTPUT);pinMode(_CLK,OUTPUT);
 pinMode(_MOSI,OUTPUT);pinMode(_MISO,INPUT);

 _soft_spi=1;
   
}



uint8_t nrf_base::RW(uint8_t byte_1)    //SPI读写
{

if(_soft_spi)
{
    uint8_t tmp=0;
    uint8_t mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};


	for( uint8_t x=0;x<8;x++)
	{
		if(byte_1 & mask[x])
                {digitalWrite(_MOSI,HIGH);}
              else
                 {digitalWrite(_MOSI,LOW);}
	
          if(digitalRead(_MISO) )
             {tmp+=mask[x];}
	 digitalWrite(_CLK,HIGH);
        digitalWrite(_CLK,LOW);
	}
    digitalWrite(_MOSI,LOW);

	return tmp;

}


else{
  SPDR=byte_1;
  while(!(SPSR & (1<<SPIF))); 
  byte_1=SPDR;
  return byte_1;
 }
}



uint8_t nrf_base::RW_Reg(uint8_t reg,uint8_t value) //寄存器访问函数：用来设置24L01 的寄存器的值。
{
  byte status_1;
  digitalWrite(_CSN,LOW);
  status_1=RW(reg);
  RW(value);
  digitalWrite(_CSN,HIGH);
  return status_1; 
}

uint8_t nrf_base::Read(uint8_t reg) //读取寄存器值的函数
{
  byte reg_val;
  digitalWrite(_CSN,LOW);
  RW(reg);
  reg_val=RW(0);
  digitalWrite(_CSN,HIGH);
  return reg_val;
}

uint8_t nrf_base::Read_Buf(uint8_t reg ,uint8_t *pBuf, uint8_t bytes) //接收缓冲区访问函
{
  byte status_1,byte_ctr;
  digitalWrite(_CSN,LOW);
  status_1=RW(reg);
  for(byte_ctr=0; byte_ctr<bytes; byte_ctr++)
  {
    pBuf[byte_ctr]=RW(0);
  }
  digitalWrite(_CSN,HIGH);
  return status_1;
}

uint8_t nrf_base::Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t bytes) //发射缓冲区访问函
{
  byte status_1,byte_ctr;
  digitalWrite(_CSN,LOW);
  status_1=RW(reg);
  //delayMicroseconds(10);
  for(byte_ctr=0; byte_ctr<bytes; byte_ctr++)
  {
    RW(*pBuf++);
  }
  digitalWrite(_CSN,HIGH);
  return status_1;
}


   

