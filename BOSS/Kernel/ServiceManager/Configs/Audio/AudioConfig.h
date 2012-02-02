
#ifndef AUDIOCONFIG_H_
#define AUDIOCONFIG_H_

#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

#define CONTROL_GENERAL_BASE (address) 0x48002000
#define PER_CM_BASE          (address) 0x48005000
#define MCBSP1_BASE          (address) 0x48074000
#define MCBSP2_BASE          (address) 0x49022000
#define I2C1_BASE            (address) 0x48070000

class AudioConfig : public ServiceConfig  {
public:
	AudioConfig();
	virtual ~AudioConfig();

	virtual void initRegistersForMmuMapping(void);
};

#endif /* AUDIOCONFIG_H_ */
