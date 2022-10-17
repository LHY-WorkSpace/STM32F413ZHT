#ifndef ST7789_H
#define ST7789_H


#define  TFT_RST_OFF  	HAL_GPIO_WritePin(TFT_RST_GPIO_Port,TFT_RST_Pin,GPIO_PIN_SET)	      //复位关
#define  TFT_RST_ON     HAL_GPIO_WritePin(TFT_RST_GPIO_Port,TFT_RST_Pin,GPIO_PIN_RESET)		  //复位开

#define  TFT_DATA      HAL_GPIO_WritePin(TFT_DC_GPIO_Port,TFT_DC_Pin,GPIO_PIN_SET)	          //数据
#define  TFT_CMD       HAL_GPIO_WritePin(TFT_DC_GPIO_Port,TFT_DC_Pin,GPIO_PIN_RESET)          //命令


#define TFT_RED     0xf800
#define TFT_GREEN   0x07e0
#define TFT_BLUE    0x001f
#define TFT_WHITE   0xffff
#define TFT_BLACK   0x0000
#define TFT_YELLOW  0xFFE0
#define TFT_GRAY0   0xEF7D   
#define TFT_GRAY1   0x8410      	
#define TFT_GRAY2   0x4208 





void ST7789_Init(void);
void ST7789_SetArea(u16 x_start,u16 y_start,u16 x_end,u16 y_end);
void ST7789_DrawPoint(u16 color);
void TFT_Full(u16 Color);


void TFT_DMA_Start(void);
void TFT_DMA_SetAddr(u32 StartAddr, u32 Point);
u32 TFT_DMA_GetCurrentAddr(void);
void TFT_DMA_SetAddr(u32 StartAddr, u32 Point);
u8 TFT_DMA_GetTXComplateFlag(void);
void TFT_DMA_Start(void);
void TFT_DMA_Stop(void);
void TFT_SwapDataForDMA(u16 *Data);
#endif
