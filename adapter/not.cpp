#include "not.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void TestNot() {
  cout << "[not] begin." << endl;

  vector<int> v = {1, 2, 3, 4, 5};

  cout << "[not] before v:" << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  vector<int> v2;
  remove_copy_if(v.begin(), v.end(), back_inserter(v2),
                 not1(bind2nd(greater_equal<int>(), 3)));

  cout << "[not] after v:" << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "[not] after v2:" << endl;
  copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "[not] end." << endl;
}