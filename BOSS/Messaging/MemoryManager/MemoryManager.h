
#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include <new>

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

	address getNextFreeAddressWith(int size);

	MemoryHeader* getNextHeader(MemoryHeader* mh);
	bool hasEnoughSpaceFor(int size, MemoryHeader* mh);

public:

	MemoryManager(address memoryStartAddress);
	virtual ~MemoryManager();

	MessageQueue* createMessageQueue();
	Message* createMessage(int taskId, int paramSize, int* messageParams);

};

#endif /* MEMORYMANAGER_H_ */
