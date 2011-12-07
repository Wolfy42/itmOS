#ifndef SERVICE_H_
#define SERVICE_H_

#include "Tasks/UserModeTask.h"

class Service : public UserModeTask
{
	protected:
		Service();
		virtual ~Service();
		
	public:
		// Service Config
};

#endif /*SERVICE_H_*/
