#include "find.h"

#include <iostream>
#include <set>
#include <vector>

using namespace std;

static void TestFind1() {
  vector<int> good = {1, 2, 3};

  auto it = find(good.begin(), good.end(), 3);
  if (it == good.end()) {
    cout << "[find] 1 no match." << endl;
    return;
  }

  cout << "[find] 1 match." << endl;
}

static void TestFind2() {
  int good[] = {1, 2, 3, 4};

  int *begin = &good[0];
  int *end = &good[4];

  auto it = find(begin, end, 4);
  if (it == end) {
    cout << "[find] 2 no match." << endl;
    return;
  }

  cout << "[find] 2 match." << endl;
}

static void TestFind3() {
  int good[] = {1, 2, 3, 4};

  set<int> good_s(good, good+4);

  auto it = find(good_s.begin(), good_s.end(), 3);
  if (it == good_s.end()) {
    cout << "[find] 3 no match." << endl;
    return;
  }

  cout << "[find] 3 match." << endl;
}

static void TestFind4() {
  vector<int> good = {1, 2, 3, 4, 5, 7, 6, 8, 9};

  auto it = adjacent_find(good.begin(), good.end(), greater<int>());
  if (it == good.end()) {
    cout << "[find] 4, no find." << endl;
    return;
  }

  cout << "[find] 4, Element " << (it - good.begin()) << " is out of order [" << *it << ", " << *(it+1) << "]" << endl;
}

void TestFind() {
  TestFind1();
  TestFind2();
  TestFind3();
  TestFind4();
}