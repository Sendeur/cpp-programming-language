#include <iostream>
#include <chrono>

#include <future>
#include <thread>

using namespace std::literals::chrono_literals;

int f(int x) {
  std::this_thread::sleep_for(std::chrono::duration(3000ms));
  std::cout << "[" << std::this_thread::get_id() << "] f returning!" << std::endl;
  return 5 + x;
}

int main() {
  std::packaged_task<int(int)> pt{f};
  std::future<int> fut = pt.get_future();

  // Version 1: run synchronously on this thread
  //pt(3);

  // Version 2: write inside a thread (packaged_task provides the operator())
  std::thread t0{std::move(pt), 5};

  std::cout << "[" << std::this_thread::get_id() << "] Main waiting for value" << std::endl;

  int value = fut.get();
  std::cout << "[" << std::this_thread::get_id() << "] Main got " << value << std::endl;

  t0.join();

  return 0;
}
