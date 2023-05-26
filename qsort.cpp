#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

static void showArr(string tag, int *arr, int n) {
  cout << "[" << tag << "]" << "show arr begin." << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
  cout << "[" << tag << "]" << "show arr end." << endl;
}

static void sort1() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, arr+n);

  showArr("sort1", arr, n);
}

static void sort2() {
  int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr+2, arr+n-1);

  showArr("sort2", arr, n);
}

static bool sort3_compare(int a, int b) {
  return a < b;
}

static void sort3() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr+1, arr+n, sort3_compare);

  showArr("sort3", arr, n);
}

class CompareA {
public:
  bool operator()(int a, int b) {
    return a < b;
  }
};

static void sort4() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr+2, arr+n-1, CompareA());

  showArr("sort4", arr, n);
}

template<class T> bool FuncCompare(T a, T b) {
  return a < b;
}

static void sort5() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, arr+n, FuncCompare<int>);

  showArr("sort5", arr, n);
}

static void sort6() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr+1, arr+n-2, greater<int>());

  showArr("sort6", arr, n);
}

void TestQsort() {
  sort1();
  sort2();
  sort3();
  sort4();
  sort5();
  sort6();
}