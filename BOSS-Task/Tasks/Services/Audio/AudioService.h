
#ifndef AUDIOSERVICE_H_
#define AUDIOSERVICE_H_

#include "Tasks/Services/Service.h"
#include "Messaging/Message/Message.h"

class AudioService : public Service {

	private:
		virtual void executeMessage(Message* message);

	public:
		AudioService();
		virtual ~AudioService();
};

#endif /* AUDIOSERVICE_H_ */
