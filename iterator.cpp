#include "iterator.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static void TestIterator_1(int argc, const char **argv) {
  vector<string> str_v;

  for (int i = 1; i < argc; i++) {
    str_v.push_back(string(argv[i]));
  }

  cout << "[iterator] test 1 begin." << endl;
  for (vector<string>::iterator iter = str_v.begin(); iter != str_v.end(); iter++) {
    cout << *iter << endl;
  }
  cout << "[iterator] test 1 end." << endl;
}

static void TestIterator_2() {
  cout << "[iterator] test 2 begin." << endl;

  vector<int> v;
  copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

  copy(v.begin(),v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "[iterator] test 2 end." << endl;
}

static void TestIterator_3() {
  // good.txt
  // 3
  // 4
  // 5
  // 6
  // 7

  cout << "[iterator] test 3 begin." << endl;
  ifstream ifs("good.txt");
  int tmp;
  while (ifs >> tmp) {
    cout << tmp << endl;
  }
  cout << "[iterator] test 3 end." << endl;

  cout << "[iterator] 3 copy begin." << endl;
  ifstream ifs2("good.txt");
  copy(istream_iterator<int>(ifs2), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "[iterator] 3 copy end." << endl;
}

void TestIterator() {
  const char *good[] = {"program", "argc_1", "argc_2", "argc_3"};
  TestIterator_1(4, good);

  // disable for cin
//  TestIterator_2();

  // disable for file
//  TestIterator_3();
}