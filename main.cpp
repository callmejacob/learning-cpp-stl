#include "algorithm/copy.h"
#include "algorithm/find.h"
#include "algorithm/qsort.h"
#include "algorithm/search.h"
#include "algorithm/fill.h"
#include "algorithm/replace.h"
#include "algorithm/remove.h"
#include "algorithm/transform.h"
#include "algorithm/for_each.h"
#include "container/vector.h"
#include "container/deque.h"
#include "container/list.h"
#include "container/set.h"
#include "container/map.h"
#include "container/multiset.h"
#include "iterator/iterator.h"
#include "other/condition.h"
#include "other/str64.h"

int main() {
  TestCondition();
  TestStr64();

  TestVector();
  TestDeque();
  TestList();
  TestSet();
  TestMap();
  TestMultiSet();

  TestIterator();

  TestQsort();
  TestSearch();
  TestFind();
  TestCopy();
  TestFill();
  TestReplace();
  TestRemove();
  TestTransform();
  TestForEach();

  return 0;
}