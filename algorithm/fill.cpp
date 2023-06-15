#include "fill.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void TestFill() {
  int good[5];
  cout << "[fill] fill int array with 100." << endl;
  fill(good, good+5, 100);
  copy(&good[0], &good[5], ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "[fill] fill int array with 200." << endl;
  fill_n(good, 5, 200);
  copy(&good[0], &good[5], ostream_iterator<int>(cout, ","));
  cout << endl;

  vector<int> v(10, 100);
  cout << "[fill] fill vector with 200." << endl;
  fill(v.begin(), v.end(), 200);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "[fill] fill vector with 300." << endl;
  fill(v.begin(), v.end(), 300);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
}