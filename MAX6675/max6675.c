#include "max6675.h"

int read_max6675(SPI_HandleTypeDef *hspi, GPIO_TypeDef *CS_GPIO_Port_usr, uint16_t CS_Pin_usr )
{
	void* data=malloc(sizeof(uint16_t));

	HAL_GPIO_WritePin(CS_GPIO_Port_usr, CS_Pin_usr, 0);
	HAL_Delay(1); // timing requirement for chip needed 100ns time before applying clock this is 1ms

	HAL_SPI_Receive(hspi, (uint8_t*)data, 2, 1000);

	HAL_GPIO_WritePin(CS_GPIO_Port_usr, CS_Pin_usr, 1);

	if((*(uint16_t*)data & 0x8006)==0) 					//0x8006=1000000000000110
			return (*(uint16_t*)data>>=3) & 0x0fff;		//0x0fff=0000111111111111
			/* return  temperature in Celsius TIMES 4 (because resolution is 0.25)	*/
	else
		return 0;
}
