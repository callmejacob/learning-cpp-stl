#include "deque.h"

#include <iostream>
#include <deque>
#include <iterator>

void TestDeque() {
  std::cout << "[deque] begin." << std::endl;

  std::deque<int> a_deck;
  a_deck.push_back(33);
  a_deck.push_front(1);
  a_deck.insert(a_deck.begin()+1, 2);
  a_deck[2] = 0;

  std::copy(a_deck.begin(), a_deck.end(), std::ostream_iterator<int>(std::cout, "\n"));

  std::cout << "[deque] test end." << std::endl;
}