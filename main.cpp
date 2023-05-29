#include "qsort.h"
#include "search.h"
#include "vector.h"
#include "deque.h"
#include "list.h"
#include "set.h"
#include "map.h"

#include "condition.h"

int main() {
  TestQsort();
  TestSearch();

  TestCondition();

  TestVector();
  TestDeque();
  TestList();
  TestSet();
  TestMap();

  return 0;
}