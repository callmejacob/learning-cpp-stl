#include "block.h"

int main(int argc, const char **argv) {

  auto p = new char('1');
  delete p;

  InitMemoryPool();

  auto pb = new char[10000];
  delete[] pb;

  CleanMemoryPool();
  return 0;
}