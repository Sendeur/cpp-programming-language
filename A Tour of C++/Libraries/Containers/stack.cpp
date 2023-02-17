#include <iostream>

#include <stack>

int main() {
  std::stack<int> s{};

  // push 1
  s.push(1);
  std::cout << "push(1)" << std::endl;
  std::cout << "top() = " << s.top() << std::endl;;

  // push 2
  s.push(2);
  std::cout << "push(2)" << std::endl;
  std::cout << "top() = " << s.top() << std::endl;;

  // push 3
  s.push(3);
  std::cout << "push(3)" << std::endl;
  std::cout << "top() = " << s.top() << std::endl;;


  // top
  std::cout << "top() = " << s.top() << std::endl;;

  // pop
  s.pop();
  std::cout << "top() = " << s.top() << std::endl;;

  // pop
  s.pop();
  std::cout << "top() = " << s.top() << std::endl;;

  // push (-1)
  s.push(-1);
  std::cout << "push(-1)" << std::endl;
  std::cout << "top() = " << s.top() << std::endl;;

  // push -2
  s.push(-2);
  std::cout << "push(-2)" << std::endl;
  std::cout << "top() = " << s.top() << std::endl;;

  // remove_if(x < 0)
  // Doesn't work!!!!
  // <stack> has no iterators!!!!

  //std::stack<int> endIt = std::remove_if(s.begin(), s.end(), [](int x) { return x < 0; });
  //s.erase(endIt, s.end();

  return 0;
}
