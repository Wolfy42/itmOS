
#include "MemoryManager.h"

MemoryManager* MemoryManager::getInstanceAt(address memoryStartAddress, int virtualOffset)  {

	address freeMemory = address((int)memoryStartAddress + sizeof(MemoryManager));
	MemoryManager* mm = new ((void*)memoryStartAddress) MemoryManager(freeMemory, virtualOffset);
	return mm;
}

MemoryManager::MemoryManager(address memoryStartAddress, int virtualOffset)  {
	_memoryStartAddress = memoryStartAddress;
	_virtualOffset = virtualOffset;

	MemoryHeader *mh = new ((void*)_memoryStartAddress) MemoryHeader();
	mh->memoryState = BOSS_MEMORY_FREE;
	mh->size = 0;

	_messageQueue = createMessageQueue();

	/* run this code to switch OFF an LED
	int a[2];
	a[0] = 0; // LED1
	a[1] = 0; // toggle

	Message* message = createMessage(1, 2, a);
	getMessageQueueWithoutVirtualOffset()->pushMessage(message);
	*/
}

MessageQueue* MemoryManager::createMessageQueue()  {
	MessageQueue* mq = (MessageQueue*)getNextFreeAddressWith(sizeof(MessageQueue));
	return (MessageQueue*)((int)new (mq) MessageQueue() + _virtualOffset);
}

Message* MemoryManager::createMessage(int taskId, int paramSize, int* messageParams)  {

	int* arr = (int*)getNextFreeAddressWith(paramSize*sizeof(int));
	memcpy(arr, messageParams, paramSize * sizeof(int));

	Message* mes = (Message*)getNextFreeAddressWith(sizeof(Message));
	return (Message*)((int)new (mes) Message(taskId, paramSize, (int*)((int)arr+_virtualOffset)) + _virtualOffset);
}

MessageQueue* MemoryManager::getMessageQueue()  {
	return _messageQueue;
}

MessageQueue* MemoryManager::getMessageQueueWithoutVirtualOffset()  {
	return (MessageQueue*)((int)_messageQueue - _virtualOffset);
}

void MemoryManager::remove(Message* message, bool isVirtual)  {

	if (!isVirtual)  {
		message = (Message*)((int)message - _virtualOffset);
	}

	int* pa = message->getParams();
	if (!isVirtual)  {
		pa = (int*)((int)pa - _virtualOffset);
	}

	MemoryHeader* mh = getHeaderForObjectAt(pa);
	mh->memoryState = BOSS_MEMORY_FREE;

	mh = getHeaderForObjectAt(message);
	mh->memoryState = BOSS_MEMORY_FREE;
}

address MemoryManager::getNextFreeAddressWith(int size)  {

	MemoryHeader* mh = (MemoryHeader*)_memoryStartAddress;
	while (!hasEnoughSpaceFor(size, mh))  {
		mh = getNextHeader(mh);
	}

	//if it is the last free memory
	if (mh->size == 0)  {
		mh->size = size;
		MemoryHeader* end = getNextHeader(mh);
		end->memoryState = BOSS_MEMORY_FREE;
		end->size = 0;
	}
	new ((void*)mh) MemoryHeader();
	mh->memoryState = BOSS_MEMORY_RESERVED;
	mh->size = size;

	return (address) ((int)mh + sizeof(MemoryHeader));
}

bool MemoryManager::hasEnoughSpaceFor(int size, MemoryHeader* mh)  {
	if (mh->memoryState == BOSS_MEMORY_FREE)  {
		if (mh->size == 0 || mh->size >= size )  {
			return true;
		}
	}
	return false;
}

MemoryHeader* MemoryManager::getNextHeader(MemoryHeader* mh)  {
	return (MemoryHeader*)((int)mh + mh->size + sizeof(MemoryHeader));
}
MemoryHeader* MemoryManager::getHeaderForObjectAt(void* address)  {
	return (MemoryHeader*)((int)address - sizeof(MemoryHeader));
}
