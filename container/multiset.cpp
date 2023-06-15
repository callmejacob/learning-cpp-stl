#include "multiset.h"

#include <iostream>
#include <set>

using namespace std;

void TestMultiSet() {
  multiset<int> A = {1, 2, 3, 4, 5, 6, 7, 8};
  multiset<int> B = {1, 2, 3, 4, 9};
  multiset<int> C;

  cout << "[A] ";
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "[B] ";
  copy(B.begin(), B.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "[union] ";
  set_union(A.begin(), A.end(), B.begin(), B.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "[intersection] ";
  set_intersection(A.begin(), A.end(), B.begin(), B.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "[difference] ";
  set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.end()));
  copy(C.begin(), C.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
}