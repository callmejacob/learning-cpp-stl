#include "transform.h"

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void TestTransform() {
  vector<float> good(5, 1);

  partial_sum(good.begin(), good.end(), good.begin());
  cout << "[transform] partial sum: " << endl;
  copy(good.begin(), good.end(), ostream_iterator<float>(cout, ","));
  cout << endl;

  transform(good.begin(), good.end(), good.begin(), good.begin(), multiplies<float>());
  cout << "[transform] multiplies: " << endl;
  copy(good.begin(), good.end(), ostream_iterator<float>(cout, ","));
  cout << endl;

  transform(good.begin(), good.end(), good.begin(), bind2nd(divides<float>(), 3));
  cout << "[transform] divides: " << endl;
  copy(good.begin(), good.end(), ostream_iterator<float>(cout, ","));
  cout << endl;
}