#ifndef GPIO_H_
#define GPIO_H_

#include "API/dataTypes.h"

// Control registers
#define CONTROL_GPIO_7 (address) 0x48002A14
#define CONTROL_GPIO_149 (address) 0x480020A8
#define CONTROL_GPIO_150 (address) 0x480020A8


#define GPIO_OE_GPIO1 (address) 0x48310034
#define GPIO_OE_GPIO2 (address) 0x49050034
#define GPIO_OE_GPIO3 (address) 0x49052034
#define GPIO_OE_GPIO4 (address) 0x49054034
#define GPIO_OE_GPIO5 (address) 0x49056034
#define GPIO_OE_GPIO6 (address) 0x49058034


#define GPIO_DATAOUT_GPIO1 (address) 0x4831003C
#define GPIO_DATAOUT_GPIO2 (address) 0x4905003C
#define GPIO_DATAOUT_GPIO3 (address) 0x4905203C
#define GPIO_DATAOUT_GPIO4 (address) 0x4905403C
#define GPIO_DATAOUT_GPIO5 (address) 0x4905603C
#define GPIO_DATAOUT_GPIO6 (address) 0x4905803C


#define GPIO_CLEARDATAOUT_GPIO1 (address) 0x48310090
#define GPIO_CLEARDATAOUT_GPIO2 (address) 0x49050090
#define GPIO_CLEARDATAOUT_GPIO3 (address) 0x49052090
#define GPIO_CLEARDATAOUT_GPIO4 (address) 0x49054090
#define GPIO_CLEARDATAOUT_GPIO5 (address) 0x49056090
#define GPIO_CLEARDATAOUT_GPIO6 (address) 0x49058090


#define GPIO_SETDATAOUT_GPIO1 (address) 0x48310094
#define GPIO_SETDATAOUT_GPIO2 (address) 0x49050094
#define GPIO_SETDATAOUT_GPIO3 (address) 0x49052094
#define GPIO_SETDATAOUT_GPIO4 (address) 0x49054094
#define GPIO_SETDATAOUT_GPIO5 (address) 0x49056094
#define GPIO_SETDATAOUT_GPIO6 (address) 0x49058094


#define GPIO_DATAIN_GPIO1 (address) 0x48310038
#define GPIO_DATAIN_GPIO2 (address) 0x49050038
#define GPIO_DATAIN_GPIO3 (address) 0x49052038
#define GPIO_DATAIN_GPIO4 (address) 0x49054038
#define GPIO_DATAIN_GPIO5 (address) 0x49056038
#define GPIO_DATAIN_GPIO6 (address) 0x49058038

#endif /*GPIO_H_*/
