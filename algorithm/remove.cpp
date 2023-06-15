#include "remove.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static void TestRemove1() {
  vector<int> v = {1, 2, 3, 4, 5};

  cout << "[remove] before:" << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  auto te = remove(v.begin(), v.end(), 3);

  cout << "[remove] after:" << endl;
  copy(v.begin(), te, ostream_iterator<int>(cout, ","));
  cout << endl;
}

struct CheckOd {
  bool operator()(int v) {
    return v % 2 == 0;
  }
};

static void TestRemove2() {
  vector<int> v = {1, 2, 3, 4, 5};

  cout << "[remove] 2, before:" << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  auto te = remove_if(v.begin(), v.end(), CheckOd());

  cout << "[remove] 2, after:" << endl;
  copy(v.begin(), te, ostream_iterator<int>(cout, ","));
  cout << endl;
}

static void TestRemove3() {
  vector<int> v = {1, 2, 3, 4, 5};

  cout << "[remove] 2, before:" << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  auto te2 = remove_if(v.begin(), v.end(), [](int v){
    return v % 2 == 1;
  });
  cout << "[remove] 2, after2:" << endl;
  copy(v.begin(), te2, ostream_iterator<int>(cout, ","));
  cout << endl;
}

void TestRemove() {
  TestRemove1();
  TestRemove2();
  TestRemove3();
}