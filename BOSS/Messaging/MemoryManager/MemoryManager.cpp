
#include "MemoryManager.h"

MemoryManager::MemoryManager(address memoryStartAddress)  {
	_memoryStartAddress = memoryStartAddress;

	MemoryHeader *mh = new ((void*)_memoryStartAddress) MemoryHeader();
	mh->memoryState = BOSS_MEMORY_FREE;
	mh->size = 0;
}

MemoryManager::~MemoryManager()  {}

MessageQueue* MemoryManager::createMessageQueue()  {

}

Message* MemoryManager::createMessage(int taskId, int paramSize, int* messageParams)  {

	int* arr = (int*)getNextFreeAddressWith(paramSize*sizeof(int));
	memcpy(arr, messageParams, paramSize * sizeof(int));

	Message* mes = (Message*)getNextFreeAddressWith(sizeof(Message));
	return new (mes) Message(taskId, paramSize, arr);
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
