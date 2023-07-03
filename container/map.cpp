#include "map.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

typedef map<string, int> MyMap;

struct print {
  void operator()(MyMap::value_type it) {
    cout << "key:" << it.first << ", count:" << it.second << endl;
  }
};

void TestNormalMap() {
  map<string, int> good_map;

  string src_tokens[] = {"good", "boy", "good", "girl", "good", "bad", "boy", "girl"};

  for (auto &token : src_tokens) {
    good_map[token]++;
  }

  for_each(good_map.begin(), good_map.end(), print());
}

void TestUnOrderMap() {
  std::unordered_map<std::string, std::string> users;

  users["a"] = "A";
  users["b"] = "B";

  auto it = users.find("a");
  if (it != users.end()) {
    cout << "[un_order_map] find it, " << it->second << endl;
  }

  it = users.find("c");
  if (it == users.end()) {
    cout << "[un_order_map] can't find it, " << "c" << endl;
  }
}

void TestMap() {
  TestNormalMap();
  TestUnOrderMap();
}