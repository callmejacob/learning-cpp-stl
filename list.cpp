#include "list.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

void TestList() {
  std::cout << "[list] test begin." << std::endl;

  std::list<std::string> a_list;
  a_list.push_back("banana");
  a_list.push_front("apple");
  a_list.push_back("carrot");

  auto out_it = std::ostream_iterator<std::string>(std::cout, "\n");

  std::cout << "[list] print by normal sequence." << std::endl;
  std::copy(a_list.begin(), a_list.end(), out_it);

  std::cout << "[list] print by reverse sequence." << std::endl;
  std::reverse_copy(a_list.begin(), a_list.end(), out_it);

  std::cout << "[list] print by reverse sequence." << std::endl;
  std::copy(a_list.rbegin(), a_list.rend(), out_it);

  std::cout << "[list] test end." << std::endl;
}