#include <iostream>

#include <future>
#include <thread>

int f(int val) {
  std::cout << "[" << std::this_thread::get_id() << "] f(" << val << ")" << std::endl;
  return val;
}

int main() {
  std::cout << "[" << std::this_thread::get_id() << "] main() started" << std::endl;

  std::future<int> f0 = std::async(std::launch::async, f, 1);
  std::future<int> f1 = std::async(std::launch::async, f, 3);
  std::future<int> f2 = std::async(std::launch::async, f, 5);
  std::future<int> f3 = std::async(std::launch::deferred, f, 7);

  int sum = f0.get() + f1.get() + f2.get() + f3.get();
  std::cout << "sum = " << sum << std::endl;

  return 0;
}
