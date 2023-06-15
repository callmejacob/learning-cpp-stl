#include "algorithm/qsort.h"
#include "algorithm/search.h"
#include "container/vector.h"
#include "container/deque.h"
#include "container/list.h"
#include "container/set.h"
#include "container/map.h"
#include "container/multiset.h"

#include "other/condition.h"

#include "iterator/iterator.h"

#include "other/str64.h"

int main() {
  TestQsort();
  TestSearch();

  TestCondition();

  TestVector();
  TestDeque();
  TestList();
  TestSet();
  TestMap();
  TestMultiSet();

  TestIterator();

  TestStr64();

  return 0;
}