#include "remove.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void TestRemove() {
  vector<int> v = {1, 2, 3, 4, 5};

  cout << "[remove] before:" << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  auto te = remove(v.begin(), v.end(), 3);

  cout << "[remove] after:" << endl;
  copy(v.begin(), te, ostream_iterator<int>(cout, ","));
  cout << endl;
}