#include <iostream>

#include <future>
#include <thread>
#include <chrono>
#include <exception>

using namespace std::literals::chrono_literals;

void f(std::promise<int> promise) {
  std::this_thread::sleep_for(std::chrono::duration(3000ms)); 

  promise.set_value(1);
}

int main() {
  std::promise<int> promise;
  std::future<int> future = promise.get_future();

  // Thread handling the promise must take ownership!
  std::thread t1{f, std::move(promise)};

  std::cout << "value = " << future.get() << std::endl;

  t1.join();

  return 0;
}
