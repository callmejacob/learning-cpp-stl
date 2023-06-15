#include "replace.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void TestReplace() {
  vector<int> g = {1, 2, 3, 1, 4, 5};

  cout << "[replace] before:" << endl;
  copy(g.begin(), g.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "[replace] after:" << endl;
  replace(g.begin(), g.end(), 1, 10);
  copy(g.begin(), g.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
}