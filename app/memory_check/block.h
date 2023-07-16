#ifndef GOOD_BLOCK_H
#define GOOD_BLOCK_H

#include <iostream>

extern std::string s_memory_info;

void InitMemoryPool();

void CleanMemoryPool();

void *operator new(std::size_t size);

void operator delete(void *p);

void *operator new[](std::size_t size);

void operator delete[](void *p);


#endif //GOOD_BLOCK_H
