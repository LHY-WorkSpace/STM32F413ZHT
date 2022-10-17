#include "DataType.h"
#include "ST7789.h"
#include "dma.h"
#include "spi.h"

//����������ݵĴ�С
#define POINT_SIZE  (sizeof(u16))

//DMA ������������
#define DMA_MAX_BUFF  (60000)

//DMA������Ʋ���
static u32 DMA_TXCurrentAddr,DMA_EndAddr;



//***************************************************//
//  ��������: TFT SPI IO��ʼ��
//  
//  ����: ��
//  
//  ����ֵ: TRUE / FALSE
//  
//  ˵��: 2��Ƶ = 40Mhz
//  PA5-------SCLK          PA7------SDA
//  PA6-------D/C           PA4------RST 
//***************************************************//
static void TFT_IOInit()
{

	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);

}

//***************************************************//
//  ��������: 7789 DMA��ʼ��
//  
//  ����: ��
//  
//  ����ֵ: TRUE / FALSE
//  
//  ˵��: ��
//  
//***************************************************//
void ST7789_DMA_Init()
{
	MX_SPI1_Init();
	MX_DMA_Init();

}


//***************************************************//
//  ��������: �������������
//  
//  ����: ����
//  
//  ����ֵ: TRUE / FALSE
//  
//  ˵��: ��
//  
//***************************************************//
static void TFT_SendData(u8 Data)
{
    TFT_DATA;
    HAL_SPI_Transmit(&hspi1, &Data, 1, 0xFFFF);
}

static void TFT_SetCmd(u8 CMD)
{
    TFT_CMD;
    HAL_SPI_Transmit(&hspi1, &CMD, 1, 0xFFFF);

}

//***************************************************//
//  ��������: ST7789 ���ó�ʼ��
//  
//  ����: ��
//  
//  ����ֵ: ��
//  
//  ˵��: ��
//  
//***************************************************//
void ST7789_Init()
{

    //TFT_IOInit();
   // ST7789_DMA_Init();

	TFT_RST_ON;
	HAL_Delay(10);
    TFT_RST_OFF;
	HAL_Delay(10);

    TFT_SetCmd(0x11); 			//Sleep Out
	HAL_Delay(120);
    TFT_SetCmd(0x3A);        //65k mode
    TFT_SendData(0x05);
    TFT_SetCmd(0xC5); 		//VCOM
    TFT_SendData(0x1A);
    TFT_SetCmd(0x36);                 // ��Ļ��ʾ��������
    TFT_SendData(0x00);
    TFT_SetCmd(0xb2);		//Porch Setting
    TFT_SendData(0x05);
    TFT_SendData(0x05);
    TFT_SendData(0x00);
    TFT_SendData(0x33);
    TFT_SendData(0x33);
    TFT_SetCmd(0xb7);			//Gate Control
    TFT_SetCmd(0xBB);//VCOM
    TFT_SendData(0x3F);
    TFT_SetCmd(0xC0); //Power control
    TFT_SendData(0x2c);
    TFT_SetCmd(0xC2);		//VDV and VRH Command Enable
    TFT_SendData(0x01);
    TFT_SetCmd(0xC3);			//VRH Set
    TFT_SendData(0x0F);		//4.3+( vcom+vcom offset+vdv)
    TFT_SetCmd(0xC4);			//VDV Set
    TFT_SendData(0x20);				//0v
    TFT_SetCmd(0xC6);				//Frame Rate Control in Normal Mode
    TFT_SendData(0X01);			//111Hz
    TFT_SetCmd(0xd0);				//Power Control 1
    TFT_SendData(0xa4);
    TFT_SendData(0xa1);
    TFT_SetCmd(0xE8);				//Power Control 1
    TFT_SendData(0x03);
    TFT_SetCmd(0xE9);				//Equalize time control
    TFT_SendData(0x09);
    TFT_SendData(0x09);
    TFT_SendData(0x08);
    TFT_SetCmd(0xE0); //Set Gamma
    TFT_SendData(0xD0);
    TFT_SendData(0x05);
    TFT_SendData(0x09);
    TFT_SendData(0x09);
    TFT_SendData(0x08);
    TFT_SendData(0x14);
    TFT_SendData(0x28);
    TFT_SendData(0x33);
    TFT_SendData(0x3F);
    TFT_SendData(0x07);
    TFT_SendData(0x13);
    TFT_SendData(0x14);
    TFT_SendData(0x28);
    TFT_SendData(0x30);
    TFT_SetCmd(0XE1); //Set Gamma
    TFT_SendData(0xD0);
    TFT_SendData(0x05);
    TFT_SendData(0x09);
    TFT_SendData(0x09);
    TFT_SendData(0x08);
    TFT_SendData(0x03);
    TFT_SendData(0x24);
    TFT_SendData(0x32);
    TFT_SendData(0x32);
    TFT_SendData(0x3B);
    TFT_SendData(0x14);
    TFT_SendData(0x13);
    TFT_SendData(0x28);
    TFT_SendData(0x2F);
    TFT_SetCmd(0x21); 		//����
    TFT_SetCmd(0x29);         //������ʾ 

    DMA_TXCurrentAddr = 0;
    DMA_EndAddr = 0;
}


//***************************************************//
//  ��������: ���û�ͼ����
//  
//  ����: ��ʼ�ͽ�������
//  
//  ����ֵ: ��
//  
//  ˵��: ��
//  
//***************************************************//
void ST7789_SetArea(u16 x_start,u16 y_start,u16 x_end,u16 y_end)
{	

	TFT_SetCmd(0x2a);
	TFT_SendData(0x00);
	TFT_SendData(x_start);
	TFT_SendData(0x00);
	TFT_SendData(x_end);

	TFT_SetCmd(0x2b);
	TFT_SendData(0x00);
	TFT_SendData(y_start);
	TFT_SendData(0x00);
	TFT_SendData(y_end);	
	TFT_SetCmd(0x2c);
}


//***************************************************//
//  ��������: ����
//  
//  ����: ��ɫֵ
//  
//  ����ֵ: 
//  
//  ˵��: ����ǰ��ָ����ͼ��Χ
//  
//***************************************************//
void ST7789_DrawPoint(u16 color)
{
    TFT_SendData(color>>8);
    TFT_SendData(color);
}


//***************************************************//
//  ��������: ����
//  
//  ����: ��ɫֵ
//  
//  ����ֵ: TRUE / FALSE
//  
//  ˵��: ��
//  
//***************************************************//
void TFT_Full(u16 color)
{
    u32 ROW,column;
    TFT_SetCmd(0x2a);     //Column address set
    TFT_SendData(0x00);    //start column
    TFT_SendData(0x00); 
    TFT_SendData(0x00);    //end column
    TFT_SendData(0xF0);

    TFT_SetCmd(0x2b);     //Row address set
    TFT_SendData(0x00);    //start row
    TFT_SendData(0x00); 
    TFT_SendData(0x00);    //end row
    TFT_SendData(0xF0);
    TFT_SetCmd(0x2C);     //Memory write
    for(ROW=0;ROW<240;ROW++)             //ROW loop
    { 
        for(column=0;column<240 ;column++) //column loop
        {
            TFT_SendData(color>>8);
            TFT_SendData(color);
        }
    }
}


//***************************************************//
//  ��������: �������ݸߵ��ֽ�
//  
//  ����: u16 ( RGB565 )
//  
//  ����ֵ: ��
//  
//  ˵��: ������Ϊ BGR 565  ,7789�Ƚ��ո��ֽ�����
//  
//***************************************************//
void TFT_SwapDataForDMA(u16 *Data)
{
    u16 Buf;

    Buf = *Data;

    *Data >>= 8;

    *Data |= (Buf&0xFF)<<8;

}

//***************************************************//
//  ��������: DMA����������ʼ��ַ�ͳ���
//  
//  ����: ���ݵ�ַ������
//  
//  ����ֵ: TRUE / FALSE
//  
//  ˵��: 
//  
//***************************************************//
void TFT_DMA_SetAddr(u32 StartAddr, u32 Point)
{
    DMA_TXCurrentAddr = StartAddr;
    DMA_EndAddr = StartAddr + Point*POINT_SIZE;
}

//***************************************************//
//  ��������: ��ȡ��ǰ���͵�ַ
//  
//  ����: ��
//  
//  ����ֵ: u32
//  
//  ˵��: ��
//  
//***************************************************//
u32 TFT_DMA_GetCurrentAddr()
{
    return DMA_TXCurrentAddr;
}

//***************************************************//
//  ��������: ��ȡDMA����״̬
//  
//  ����: 
//  
//  ����ֵ: TRUE�������/ FALSE��δ���
//  
//  ˵��: ��
//  
//***************************************************//
u8 TFT_DMA_GetTXComplateFlag()
{
    if( DMA_TXCurrentAddr < DMA_EndAddr )
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

//***************************************************//
//  ��������: ����DMA����
//  
//  ����: ��
//  
//  ����ֵ: ��
//  
//  ˵��: ����DMA����ʱ�ȵ��� TFT_DMA_SetAddr(),ȷ��������ʼ��ַ�ͳ���
//        �ж���ֱ�ӵ���
//***************************************************//
void TFT_DMA_Start()
{
    u32 Length;

    TFT_DATA;

    Length = (DMA_EndAddr - DMA_TXCurrentAddr);

    if( Length > DMA_MAX_BUFF )
    {
         Length = DMA_MAX_BUFF;
    }

    HAL_DMA_DeInit(&hdma_spi1_tx);
    HAL_DMAEx_ChangeMemory(&hdma_spi1_tx, DMA_TXCurrentAddr, MEMORY0);
    HAL_DMA_Start_IT(&hdma_spi1_tx, DMA_TXCurrentAddr, (u32)&(hspi1.Instance->DR), Length);

    DMA_TXCurrentAddr += Length;

}

//***************************************************//
//  ��������: ֹͣDMA
//  
//  ����: ��
//  
//  ����ֵ: 
//  
//  ˵��: ���ݴ��䵽���趨���Ⱥ�ֹͣDMA
//  
//***************************************************//
void TFT_DMA_Stop()
{
    HAL_DMA_Abort_IT(&hdma_spi1_tx);
    DMA_TXCurrentAddr = 0;
    DMA_EndAddr = 0;

}







