#include <iostream>
#include <vector>

#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::vector<int> values;
std::mutex valuesMutex;
std::condition_variable cond_var;

// condition_variable WORKS ONLY WITH std::unique_lock<std::mutex> !!!!!!!!!

using namespace std::chrono_literals;

void producer() {
  int val = 0;

  while (true) {
    {
      std::unique_lock<std::mutex> lock{valuesMutex};

      std::cout << "[producer] wrote val=" << val << std::endl;

      values.push_back(val);
      val++;
    }

    // Notify consumer
    cond_var.notify_one();

    std::this_thread::sleep_for(std::chrono::duration(250ms));
  }
}

void consumer() {
  int val;

  while (true) {
    // Acquire lock
    std::unique_lock<std::mutex> lock{valuesMutex};
    // Wait for condition. Upon waking up, it acquires the lock & checks the condition.
    // * if condition==false, release lock and sleep
    cond_var.wait(lock, []() { return !values.empty(); });

    val = values.back();
    values.pop_back();
    std::cout << "[consumer] read val=" << val << std::endl;

    std::this_thread::sleep_for(std::chrono::duration(250ms));
  }
}

int main() {
  std::thread producerThread{producer};
  std::thread consumerThread{consumer};

  producerThread.join();
  consumerThread.join();

  return 0;
}
