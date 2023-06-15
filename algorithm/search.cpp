#include "search.h"

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

static void showArr(string tag, int *arr, int n) {
  cout << "[" << tag << "] begin." << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
  cout << "[" << tag << "] end." << endl;
}

static void search1() {
  int arr[] = {9, 7, 3, 5, 2, 1, 4, 6, 8};
  int n = sizeof(arr)/sizeof(arr[0]);

  showArr("search1", arr, n);

  sort(arr, arr+n);

  if (binary_search(arr, arr+n, 2)) {
    cout << "hit it!" << endl;
  } else {
    cout << "not catch it!" << endl;
  }

  if (binary_search(arr, arr+n, 10)) {
    cout << "hit it!" << endl;
  } else {
    cout << "not catch it!" << endl;
  }
}

void TestSearch() {
  cout << "here is TestSearch." << endl;
  search1();
}