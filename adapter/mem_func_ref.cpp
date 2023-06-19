#include "mem_func_ref.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class WrapInt {
public:
  WrapInt (): val_ (0) {}
  WrapInt(int x): val_ (x) {}
  void showval() {
    std::cout << val_ << " ";
  }
  bool is_prime() {
    for (int i = 2; i <= (val_ / 2); i++)
      if ((val_ % i) == 0)
        return false;
    return true;
  }
private:
  int val_;
};

void TestMemFunRef() {
  cout << "[mem_fun_ref] begin." << endl;

  vector<int> v = {1, 3, 5, 2, 4};

//  for_each (v.begin (), v.end(), std::mem_fun_ref (&WrapInt::showval));

//
//  transform(v.begin(), v.end(),
//            ostream_iterator<int>(cout, " "),
//
//                mem_fun_ref(&string::size));

//  std::transform(v.begin(), v.end(),
//                 std::ostream_iterator<std::size_t>(std::cout, " "),
//                 std::mem_fun_ref(&std::string::size));

  cout << "[mem_fun_ref] end." << endl;
}