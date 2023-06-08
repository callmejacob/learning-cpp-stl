#include "iterator.h"

#include <fstream>
#include <iostream>
#include <list>
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

  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
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

template<typename ForwardIterator, typename T>
static void my_replace(ForwardIterator first, ForwardIterator last, const T &old_v, const T &new_v) {
  for (; first != last; first++) {
    if (*first == old_v) {
      *first = new_v;
    }
  }
}

static void TestIterator_4() {
  vector<int> good = {1, 2, 3, 2};

  cout << "[iterator] 4 print old vector." << endl;
  copy(good.begin(), good.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  my_replace(good.begin(), good.end(), 2, 8);

  cout << "[iterator] 4 print new vector. (my_replace)" << endl;
  copy(good.begin(), good.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  replace(good.begin(), good.end(), 8, 9);

  cout << "[iterator] 4 print new vector. (std::replace)" << endl;
  copy(good.begin(), good.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

template<typename BiDirectoryIterator, typename Compare>
static void BubbleSort(BiDirectoryIterator first, BiDirectoryIterator last, Compare comp) {
  BiDirectoryIterator left_it = first;
  BiDirectoryIterator right_it = first;
  ++right_it;
  while (first != last) {
    while (right_it != last) {
      if (comp(*left_it, *right_it)) {
        swap(*left_it, *right_it);
      }

      ++right_it;
      ++left_it;
    }

    last--;
    left_it = first;
    right_it = first;
    ++right_it;
  }
}

void TestIterator_5() {
  cout << "[iterator] 5 begin." << endl;

  list<int> good = {1, 5, 2, 6, 7, 9, 3};
  cout << "[iterator] 5 before bubble sort." << endl;
  copy(good.begin(), good.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  BubbleSort(good.begin(), good.end(), [](int left, int right) {
    return left <= right;
  });

  cout << "[iterator] 5 after bubble sort." << endl;
  copy(good.begin(), good.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "[iterator] 5 end." << endl;
}

void TestIterator() {
  const char *good[] = {"program", "argc_1", "argc_2", "argc_3"};
  TestIterator_1(4, good);

  // disable for cin
//  TestIterator_2();

  // disable for file
//  TestIterator_3();

  TestIterator_4();
  TestIterator_5();
}