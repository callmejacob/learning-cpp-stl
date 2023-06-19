#include "for_each.h"

#include <iostream>

using namespace std;

void TestForEach() {
  cout << "[for_each] begin." << endl;

  int arr[5] = {1, 2, 5, 4, 3};

  for_each(arr, arr+5, [](const int &v){
    cout << "[for_each] item:" << v << endl;
  });

  cout << "[for_each] end." << endl;
}