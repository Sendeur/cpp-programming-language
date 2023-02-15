#include <iostream>

#include <deque>
#include <algorithm>

template<typename Container>
void printc(const Container& c) {
  typename Container::const_iterator it;

  for (it = c.begin(); it != c.end(); it++)
    std::cout << *it << ", ";
  std::cout << std::endl << std::endl;
}

int main() {
  std::deque<int> q{1, 2, 3, 4, 5, 6, 7};

  // Remove 5
  std::deque<int>::iterator it = std::find(q.begin(), q.end(), 5);
  q.erase(it);
  std::cout << "5 erased" << std::endl;
  printc(q);

  // Remove 1
  q.pop_front();
  std::cout << "1 erased" << std::endl;
  printc(q);

  // Remove 7
  q.pop_back();
  std::cout << "7 erased" << std::endl;
  printc(q);

  // q.front.insert(-1)
  q.push_front(-1);
  std::cout << "-1 inserted" << std::endl;
  printc(q);

  // q.back.insert(-7)
  q.push_back(-7);
  std::cout << "-7 inserted" << std::endl;
  printc(q);

  // print front, back
  int front = q.front();
  int back = q.back();
  std::cout << "front = " << front << ", back = " << back << std::endl;

  // print q[4]
  std::cout << "q[4] == " << q[4] << std::endl;
  printc(q);

  // Remove all negative numbers
  auto endIt = std::remove_if(q.begin(), q.end(), [](int x) { return x < 0; });
  q.erase(endIt, q.end());
  printc(q);

  return 0;
}
