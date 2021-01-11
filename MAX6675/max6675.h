#ifndef MAX6675
#define MAX6675
#include <main.h>
#include <stdlib.h>

int read_max6675(SPI_HandleTypeDef *hspi, GPIO_TypeDef *CS_GPIO_Port_usr, uint16_t CS_Pin_usr );

#endif
