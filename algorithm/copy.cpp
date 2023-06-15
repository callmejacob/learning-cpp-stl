#include "copy.h"

#include <iostream>
#include <vector>

using namespace std;

void TestCopy() {
  vector<int> s = {1, 2, 3, 4, 5};
  vector<int> v = {};

  copy(s.begin(), s.end(), back_inserter(v));
  copy(v.begin(), v.end(), ostream_iterator<int>(cout));
  cout << endl;
}