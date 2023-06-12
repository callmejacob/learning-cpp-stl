#include "str64.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static string convertInt64ToString(::int64_t v) {
  std::ostringstream tmp;
  tmp << v;
  return tmp.str();
}

static ::int64_t convertStringToInt64(std::string s) {
  std::istringstream is(s);
  ::int64_t v;
  is >> v;
  return v;
}

void TestStr64() {
  ::int64_t current_time_v = 1686541282;
  string current_time_s = "1686541282";

  cout << "time str:" << convertInt64ToString(current_time_v) << endl;
  cout << "time v:" << convertStringToInt64(current_time_s) << endl;
}