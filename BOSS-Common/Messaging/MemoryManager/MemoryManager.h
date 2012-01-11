
#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include <new>
#include <string.h>

#include "API/dataTypes.h"
#include "Messaging/Message/Message.h"
#include "Messaging/MessageQueue/MessageQueue.h"

enum MemoryState  {
	BOSS_MEMORY_FREE,
	BOSS_MEMORY_RESERVED
};

struct MemoryHeader  {
	int memoryState;
	int size;
};

class MemoryManager {

private:

	address _memoryStartAddress;
	int _virtualOffset;
	MessageQueue* _messageQueue;

	MessageQueue* createMessageQueue();
	address getNextFreeAddressWith(int size);

	MemoryHeader* getNextHeader(MemoryHeader* mh);
	MemoryHeader* getHeaderForObjectAt(void* address);
	bool hasEnoughSpaceFor(int size, MemoryHeader* mh);

public:

	static MemoryManager* getInstanceAt(address memoryStartAddress, int virtualOffset);

	MemoryManager(address memoryStartAddress, int virtualOffset);

	MessageQueue* getMessageQueue();
	MessageQueue* getMessageQueueWithoutVirtualOffset();

	Message* createMessage(int taskId, int paramSize, int* messageParams);
	void remove(Message* message, bool isVirtual);

};

#endif /* MEMORYMANAGER_H_ */
