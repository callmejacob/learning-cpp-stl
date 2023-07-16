#include "block.h"

#include <iostream>
#include <string>
#include <stdio.h>

std::string s_memory_info;

typedef struct MemoryNodeHead {
  std::size_t used_size = 0;
} MemoryNodeHead;

typedef struct MemoryNodeB16 {
  MemoryNodeHead head;
  char buffer[16];
} MemoryNodeB16;

typedef struct MemoryNodeB64 {
  MemoryNodeHead head;
  char buffer[64];
} MemoryNodeB64;

typedef struct MemoryNodeB256 {
  MemoryNodeHead head;
  char buffer[256];
} MemoryNodeB256;

typedef struct MemoryNodeK1 {
  MemoryNodeHead head;
  char buffer[1024];
} MemoryNodeK1;

typedef struct MemoryNodeK2 {
  MemoryNodeHead head;
  char buffer[2048];
} MemoryNodeK2;

typedef struct MemoryNodeK4 {
  MemoryNodeHead head;
  char buffer[4096];
} MemoryNodeK4;

typedef struct MemoryNodeK16 {
  MemoryNodeHead head;
  char buffer[1024 * 16];
} MemoryNodeK16;

typedef struct MemoryNodeK64 {
  MemoryNodeHead head;
  char buffer[1024 * 64];
} MemoryNodeK64;

typedef struct MemoryNodeK256 {
  MemoryNodeHead head;
  char buffer[1024 * 256];
} MemoryNodeK256;

typedef struct MemoryNodeM1 {
  MemoryNodeHead head;
  char buffer[1024 * 1024 * 1];
} MemoryNodeM1;

typedef struct MemoryNodeM2 {
  MemoryNodeHead head;
  char buffer[1024 * 1024 * 2];
} MemoryNodeM2;

typedef struct MemoryNodeM4 {
  MemoryNodeHead head;
  char buffer[1024 * 1024 * 4];
} MemoryNodeM4;

typedef struct MemoryNodeM16 {
  MemoryNodeHead head;
  char buffer[1024 * 1024 * 16];
} MemoryNodeM16;

#define FIELD_MEMORY_NODE(level, size) \
    MemoryNode##level m_##level##_[size]; \
    std::size_t m_##level##_pos_ = 0;

typedef struct MemoryPool {
  char head[0];

  FIELD_MEMORY_NODE(B16, 100000)
  FIELD_MEMORY_NODE(B64, 100000)
  FIELD_MEMORY_NODE(B256, 100000)

  FIELD_MEMORY_NODE(K1, 40000)
  FIELD_MEMORY_NODE(K2, 20000)
  FIELD_MEMORY_NODE(K4, 10000)
  FIELD_MEMORY_NODE(K16, 6400)
  FIELD_MEMORY_NODE(K64, 1600)
  FIELD_MEMORY_NODE(K256, 400)

  FIELD_MEMORY_NODE(M1, 200)
  FIELD_MEMORY_NODE(M2, 100)
  FIELD_MEMORY_NODE(M4, 50)
  FIELD_MEMORY_NODE(M16, 10)

  char tail[0];
} MemoryPool;

typedef struct MemorySeekInfo {
  std::size_t capacity;
  MemoryNodeHead *head;
  std::size_t *item_pos;
  std::size_t item_size;
  std::size_t item_count;

  friend
  std::ostream &operator<<(std::ostream &os, const MemorySeekInfo &info) {
    os << "capacity:" << info.capacity
        << ", item_pos:" << *info.item_pos
        << ", item_size:" << info.item_size
        << ", item_count:" << info.item_count
        << std::endl;
    return os;
  }

} MemorySeekInfo;

MemoryPool *s_memory_pool = nullptr;

MemorySeekInfo memory_seek_info[20];
int memory_seek_info_count = 0;

#define INIT_MEMORY_SEEK_INFO(index, level) \
  memory_seek_info[index].capacity = sizeof(MemoryNode##level) - sizeof(MemoryNodeHead); \
  memory_seek_info[index].head = (MemoryNodeHead*)(&s_memory_pool->m_##level##_[0]); \
  memory_seek_info[index].item_pos = &s_memory_pool->m_##level##_pos_; \
  memory_seek_info[index].item_size = sizeof(MemoryNode##level); \
  memory_seek_info[index].item_count = sizeof(s_memory_pool->m_##level##_)/sizeof(MemoryNode##level);

void InitMemoryPool() {
  s_memory_pool = (MemoryPool *) malloc(1024 * 1024 * 1024 * 2L);

  INIT_MEMORY_SEEK_INFO(0, B16)
  INIT_MEMORY_SEEK_INFO(1, B64)
  INIT_MEMORY_SEEK_INFO(2, B256)

  INIT_MEMORY_SEEK_INFO(3, K1)
  INIT_MEMORY_SEEK_INFO(4, K2)
  INIT_MEMORY_SEEK_INFO(5, K4)
  INIT_MEMORY_SEEK_INFO(6, K16)
  INIT_MEMORY_SEEK_INFO(7, K64)
  INIT_MEMORY_SEEK_INFO(8, K256)

  INIT_MEMORY_SEEK_INFO(9, M1)
  INIT_MEMORY_SEEK_INFO(10, M2)
  INIT_MEMORY_SEEK_INFO(11, M4)
  INIT_MEMORY_SEEK_INFO(12, M16)

  memory_seek_info_count = 13;
}

static void *find_block(std::size_t n) {
  std::cout << "[find_block] need size:" << n << std::endl;
  for (int index = 0; index < memory_seek_info_count; index++) {
    auto &item = memory_seek_info[index];
    std::cout << "[find_block] " << item << std::endl;
    if (item.capacity >= n) {
      char *head = (char *) item.head;

      // 先按正常节奏往前进
      if (*item.item_pos < item.item_count) {
        MemoryNodeHead *p = (MemoryNodeHead *) (head + (*item.item_pos) * item.item_size);
        if (p->used_size == 0) {
          p->used_size = n;
          *item.item_pos = *item.item_pos + 1;
          std::cout << "[find_block] get it!" << std::endl;
          return (void *) ((char *) p + sizeof(MemoryNodeHead));
        }
      }

      // 耗尽了index,从头遍历寻找空余的,效率会比较低.
      for (std::size_t i = 0; i < item.item_count; i++) {
        MemoryNodeHead *p = (MemoryNodeHead *) (head + i * item.item_size);
        if (p->used_size == 0) {
          p->used_size = n;
          return (void *) ((char *) p + sizeof(MemoryNodeHead));
        }
      }

      break;
    }
  }

  auto pp = malloc(n);
  std::cout << "[find_block] use system malloc." << pp << std::endl;
  return pp;
}

static void free_block(void *p) {
  std::cout << "[block] free " << p
            << ", pool_begin:" << &s_memory_pool->head
            << ", pool_end:" << &s_memory_pool->tail
            << std::endl;
  if (p >= &s_memory_pool->head && p < &s_memory_pool->tail) {
    MemoryNodeHead *head = (MemoryNodeHead*)((char*)p - sizeof(MemoryNodeHead));
    head->used_size = 0;
    std::cout << "[block] block free done" << std::endl;
  } else {
    free(p);
    std::cout << "[block] system free done" << std::endl;
  }
}

void CleanMemoryPool() {
  free(s_memory_pool);
  s_memory_pool = nullptr;
}

void *operator new(std::size_t size) {
  return find_block(size);
}

void operator delete(void *p) {
  free_block(p);
}

void *operator new[](std::size_t size) {
  return find_block(size);
}

void operator delete[](void *p) {
  free_block(p);
}
