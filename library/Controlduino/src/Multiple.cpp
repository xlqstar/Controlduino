/**
 * Copyright (c) 2015 by Mylife1213 <mylife1213@gmail.com>
 * Nrf24l01P library for Arduino.
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 * version v1.1
 **/



#include"Multiple.h"



Multiple::Multiple(uint8_t ce, uint8_t csn):nrf_base(ce, csn)
{
      //默认
      _EN_AA=0x3f;
     _EN_RXADDR=0x3f;
     _SETUP_RETR=0x00;
     _RF_CH=10;
     _RF_SETUP=0x26;
     _SETUP_AW=0x03;
     _CONFIG=0x7f;
     _RX_PW=32;

     _TX_EN_AA=0x3f;
     _TX_EN_RXADDR=0x3f;
     _TX_SETUP_RETR=0x00;
     _TX_RF_CH=10;
     _TX_RF_SETUP=0x26;
     _TX_SETUP_AW=0x03;
     _TX_CONFIG=0x7e;
     _TX_PW=32; 
     
}


Multiple::Multiple(uint8_t ce, uint8_t csn,uint8_t clk,uint8_t mosi,uint8_t miso):nrf_base(ce,csn,clk,mosi,miso)
{
      //默认
      _EN_AA=0x3f;
     _EN_RXADDR=0x3f;
     _SETUP_RETR=0x00;
     _RF_CH=10;
     _RF_SETUP=0x26;
     _SETUP_AW=0x03;
     _CONFIG=0x7f;
     _RX_PW=32;

     _TX_EN_AA=0x3f;
     _TX_EN_RXADDR=0x3f;
     _TX_SETUP_RETR=0x00;
     _TX_RF_CH=10;
     _TX_RF_SETUP=0x26;
     _TX_SETUP_AW=0x03;
     _TX_CONFIG=0x7e;
     _TX_PW=32; 
     
     
}



uint8_t Multiple::read_mode(uint8_t *p1, uint8_t* p2_p5)
{
  digitalWrite(_CE,LOW);
  Write_Buf(WRITE_REG  + RX_ADDR_P1 ,p1 ,5);//RX_P1节点地址
  RW_Reg(WRITE_REG + RX_ADDR_P2 ,*(p2_p5+1) );
  RW_Reg(WRITE_REG + RX_ADDR_P3 ,*(p2_p5+2) );
  RW_Reg(WRITE_REG + RX_ADDR_P4 ,*(p2_p5+3) );
  RW_Reg(WRITE_REG + RX_ADDR_P5 ,*(p2_p5+4) );
  RW_Reg(WRITE_REG + EN_AA , _EN_AA); //使能AUTO ACK
  RW_Reg(WRITE_REG + EN_RXADDR , _EN_RXADDR); //使能接收通道
  RW_Reg(WRITE_REG + SETUP_RETR ,_SETUP_RETR); //自动重发次数
  RW_Reg(WRITE_REG + RF_CH , _RF_CH); //通讯频道
  RW_Reg(WRITE_REG + RF_SETUP , _RF_SETUP); //发射参数
  RW_Reg(WRITE_REG + SETUP_AW , _SETUP_AW);//地址宽度
  RW_Reg(WRITE_REG + RX_PW_P0 , _RX_PW); //通道0数据宽度
  RW_Reg(WRITE_REG + RX_PW_P1 , _RX_PW); //通道1数据宽度
  RW_Reg(WRITE_REG + RX_PW_P2 , _RX_PW); //通道2数据宽度
  RW_Reg(WRITE_REG + RX_PW_P3 , _RX_PW); //通道3数据宽度
  RW_Reg(WRITE_REG + RX_PW_P4 , _RX_PW); //通道4数据宽度
  RW_Reg(WRITE_REG + RX_PW_P5 , _RX_PW); //通道5数据宽度    
  RW_Reg(WRITE_REG + STATUS, 0xFF); //清除中断
  Read(FLUSH_RX);//清除RX缓冲器
  Read(FLUSH_TX);//清除TX缓冲器
  RW_Reg(WRITE_REG + CONFIG, _CONFIG);
  digitalWrite(_CE,HIGH); 
  
  return 0;
}

uint8_t Multiple::send_mode(uint8_t *p0 )
{
  digitalWrite(_CE,HIGH);  
  Write_Buf(WRITE_REG  + TX_ADDR , p0 , 5); 
  Write_Buf(WRITE_REG  + RX_ADDR_P0 , p0 , 5);//RX_P0节点地址   
  RW_Reg(WRITE_REG + EN_AA , _TX_EN_AA); //使能AUTO ACK
  RW_Reg(WRITE_REG + EN_RXADDR , _TX_EN_RXADDR ); //使能接收通道
  RW_Reg(WRITE_REG + SETUP_RETR ,_TX_SETUP_RETR ); //自动重发次数
  RW_Reg(WRITE_REG + RF_CH , _TX_RF_CH); //通讯频道
  RW_Reg(WRITE_REG + RF_SETUP , _TX_RF_SETUP); //发射参数
  RW_Reg(WRITE_REG + SETUP_AW , _TX_SETUP_AW );//地址宽度
  RW_Reg(WRITE_REG + RX_PW_P0 , _TX_PW); //通道0数据宽度
  RW_Reg(WRITE_REG + RX_PW_P1 , _TX_PW); //通道1数据宽度
  RW_Reg(WRITE_REG + RX_PW_P2 , _TX_PW); //通道2数据宽度
  RW_Reg(WRITE_REG + RX_PW_P3 , _TX_PW); //通道3数据宽度
  RW_Reg(WRITE_REG + RX_PW_P4 , _TX_PW); //通道4数据宽度
  RW_Reg(WRITE_REG + RX_PW_P5 , _TX_PW); //通道5数据宽度    
  RW_Reg(WRITE_REG + STATUS, 0xFF); //清除中断
  Read(FLUSH_RX);//清除RX缓冲器
  Read(FLUSH_TX);//清除TX缓冲器
  RW_Reg(WRITE_REG + CONFIG, 0x7C);
  digitalWrite(_CE,LOW);
  
  return 0;
}

uint8_t Multiple::send(uint8_t* addr, uint8_t* data)
{ 
  digitalWrite(_CE,LOW);
  Read(FLUSH_TX);
  RW_Reg(WRITE_REG + STATUS,0xff);
  Write_Buf(WRITE_REG  + TX_ADDR , addr , 5); 
  Write_Buf(WRITE_REG  + RX_ADDR_P0 ,addr , 5);
  Write_Buf(W_TX_PAYLOAD,data,_TX_PW);  
  digitalWrite(_CE,HIGH);
  delayMicroseconds(15);
  RW_Reg(WRITE_REG + CONFIG ,_TX_CONFIG);
  digitalWrite(_CE,LOW); 

  return 0;
}


void Multiple::Interrup(uint8_t pin,void (*func)() )
{
  RW_Reg(WRITE_REG + CONFIG, 0x3f);
  attachInterrupt(pin,func, FALLING);
}

uint8_t Multiple::Interrup_read(uint8_t channel,uint8_t* data)
{

  channel=(Read(STATUS) & 0x0E)>>1;
  RW_Reg(WRITE_REG + STATUS, 0xFF);
  Read_Buf(R_RX_PAYLOAD , data , _RX_PW); 
  return 0;
}

uint8_t Multiple::read(uint8_t channel,uint8_t* data)
{
  uint8_t tmp;
  if( Read(7)& 0x40)
    {
      Interrup_read(channel, data);
      return 1;
     }
  return 0;
}


int Multiple::set_reg(String reg, String data)
{
  uint8_t tmp;

//-------------命令检查模块-------------     
  
  boolean cmd_tmp=false;
  boolean data_tmp=false;
  boolean cmd_RF_Channel=false;

  String cmd[]={"Mode","Power","CRC","RF_Power","Rate","RF_Channel","NULL"};

  String cmd_data[]={"Receive","Send","up","Down","16bit","8bit","0dBm","-6dBm","-12dBm","-18dBm","1M","2M","250k","NULL"};

for(uint8_t i=0;cmd[i]!="NULL";i++)
{
  if(reg==cmd[i])
     {cmd_tmp=true;}
  if(reg=="RF_Channel")
     {cmd_RF_Channel=true;}
} 

if(!cmd_tmp)
   { return 1000;}

for(uint8_t i=0;cmd_data[i]!="NULL";i++)
 {
   if(data==cmd_data[i])
     {data_tmp=true;}
}  

if(!cmd_RF_Channel && !cmd_RF_Channel)
  { return 1001;}

//-------------命令检查模块---------------//
  

digitalWrite(_CE,LOW);
  if(reg=="Mode")
    {
       tmp=Read(0x00);
       if(data=="Receive")
           {tmp |=0x01;}
       else if(data=="Send")
           {tmp &=0xfe;}
       
       RW_Reg(WRITE_REG + 0x00,tmp);
     } 
  if(reg=="Power")
    {
       tmp=Read(0x00);
       if(data=="up")
          { tmp |=0x02;}
       else if(data=="Down")
          { tmp &=0xfd;}
       
       RW_Reg(WRITE_REG + 0x00,tmp);
     }    
  if(reg=="CRC")
    {
       tmp=Read(0x00);
       if(data=="16bit")
           {tmp |=0x04;}
       else if(data=="8bit")
           {tmp &=0xfb;}
       
       RW_Reg(WRITE_REG + 0x00,tmp);
     } 
//-----------------CONFIG--------------

  if(reg=="RF_Power")
    {
       tmp=Read(0x06);
       if(data=="0dBm")
           {tmp |=0x07;}
       else if(data=="-6dBm")
         {  tmp &=0xf9;
           tmp |=0x04; }
       else if(data=="-12dBm")
         {  tmp &=0xf9;
           tmp |=0x02; }
       else if(data=="-18dBm")
         {  tmp &=0xf9;
           tmp |=0x00; }     
       RW_Reg(WRITE_REG + 0x06,tmp);
      }
  if(reg=="Rate")
    {
       tmp=Read(0x06);
       if(data=="1M")
         {  tmp &=0xd7;
           tmp |=0x00; }
       else if(data=="2M")
         {  tmp &=0xd7;
           tmp |=0x08; }
       else if(data=="250k")
         {  tmp &=0xd7;
           tmp |=0x20; } 
       RW_Reg(WRITE_REG + 0x06,tmp);
     }
  if(reg=="RF_Channel")
    {
       tmp=atof(data.c_str());

       RW_Reg(WRITE_REG + 0x05,tmp);
     }
  
  
digitalWrite(_CE,HIGH);
return tmp;

}


