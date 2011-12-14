#ifndef SERVICECONFIG_H_
#define SERVICECONFIG_H_

class ServiceConfig 
{	
	protected:
		std::list<address> _registersForMmuMapping;
		virtual void initRegistersForMmuMapping(void) = 0;
		
	public:
		ServiceConfig() {};
		virtual ~ServiceConfig() {};
		
		virtual char* getServiceName(void) = 0;
		virtual int getInitAddress(void) = 0;
		std::list<address> getRegistersForMmuMapping(void) { return _registersForMmuMapping; }
};

#endif /*SERVICECONFIG_H_*/
