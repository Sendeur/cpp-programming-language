#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std::literals::chrono_literals;

std::mutex cout_mutex;

void f(std::promise<int> promise) {
  std::this_thread::sleep_for(std::chrono::duration(2000ms));
  promise.set_value(1);
}

void g(std::shared_future<int> future) {
  int value = future.get();

  std::unique_lock<std::mutex> lock{cout_mutex};
  std::cout << "[" << std::this_thread::get_id() << "] value = " << value << std::endl;
}

int main() {
  std::promise<int> promise;
  std::shared_future<int> future = promise.get_future().share();

  // Writer thread
  std::thread wr{f, std::move(promise)};

  // Reader threads
  std::thread r0{g, future};
  std::thread r1{g, future};
  std::thread r2{g, future};

  wr.join();
  r0.join();
  r1.join();
  r2.join();

  return 0;
}
