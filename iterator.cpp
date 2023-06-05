#include "iterator.h"

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

void TestIterator() {
  const char *good[] = {"program", "argc_1", "argc_2", "argc_3"};
  TestIterator_1(4, good);
}