#include "vector.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void TestVector() {
  std::vector<int> good;

  good.push_back(11);
  good.push_back(22);
  good.push_back(33);

  cout << "[vector] print vector begin." << endl;
  auto iter = good.begin();
  while (iter != good.end()) {
    cout << "[vector] here is: " << *iter << endl;
    iter++;
  }
  cout << "[vector] the 3rd item is: " << good[2] << endl;
  cout << "[vector] print vector end." << endl;
}