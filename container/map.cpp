#include "map.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<string, int> MyMap;

struct print {
  void operator()(MyMap::value_type it) {
    cout << "key:" << it.first << ", count:" << it.second << endl;
  }
};

void TestMap() {
  map<string, int> good_map;

  string src_tokens[] = {"good", "boy", "good", "girl", "good", "bad", "boy", "girl"};

  for (auto &token : src_tokens) {
    good_map[token]++;
  }

  for_each(good_map.begin(), good_map.end(), print());
}