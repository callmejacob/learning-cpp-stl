#include "qsort.h"
#include "search.h"
#include "vector.h"
#include "deque.h"
#include "list.h"
#include "set.h"

#include "condition.h"

int main() {
  TestQsort();
  TestSearch();

  TestCondition();

  TestVector();
  TestDeque();
  TestList();
  TestSet();

  return 0;
}