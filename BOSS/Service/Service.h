#ifndef SERVICE_H_
#define SERVICE_H_

class Service {
	protected:
		virtual void start() = 0;
	public:
		Service();
		virtual ~Service();
		
		bool run();
		virtual bool stop() = 0;
		bool restart();
	
};

#endif /*SERVICE_H_*/
