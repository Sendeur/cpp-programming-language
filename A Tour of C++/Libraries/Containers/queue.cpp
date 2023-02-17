#include <iostream>

#include <queue>
#include <list>

int main() {
  std::queue<int, std::list<int>> q;

  q.push(1);
  std::cout << "push(1)" << std::endl;
  q.push(2);
  std::cout << "push(2)" << std::endl;
  q.push(3);
  std::cout << "push(3)" << std::endl;
  std::cout << "back() = " << q.back() << ", front() = " << q.front() << std::endl;

  q.pop();
  std::cout << "pop()" << std::endl;
  std::cout << "back() = " << q.back() << ", front() = " << q.front() << std::endl;

  q.pop();
  std::cout << "pop()" << std::endl;
  std::cout << "back() = " << q.back() << ", front() = " << q.front() << std::endl;



  return 0;
}
