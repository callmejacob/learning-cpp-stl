#include "set.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

void TestSet() {
  cout << "[set] test begin." << endl;

  set<int> a_set;

  for (int i = 0; i < 5; i++) {
    a_set.insert(i*10);
  }

  pair<set<int>::iterator, bool> ret = a_set.insert(20);
  assert(ret.second == false);

  int nums[] = {5, 10, 15};
  a_set.insert(nums, nums+3);

  copy(a_set.begin(), a_set.end(), ostream_iterator<int>(cout, "\n"));

  cout << "[set] test end." << endl;
}