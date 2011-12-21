#ifndef SERVICECONFIG_H_
#define SERVICECONFIG_H_

class ServiceConfig 
{	
	protected:
		std::list<address>* _registersForMmuMapping;
		virtual void initRegistersForMmuMapping(void) = 0;
		
	public:
		ServiceConfig() { _registersForMmuMapping = new std::list<address>; };
		virtual ~ServiceConfig() {};
		
		std::list<address>* getRegistersForMmuMapping(void) { return _registersForMmuMapping; }
};

#endif /*SERVICECONFIG_H_*/
