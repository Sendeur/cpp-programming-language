#include <iostream>

#include <mutex>
#include <thread>
#include <vector>
#include <chrono>

int x = 0;
std::mutex xMutex;
std::mutex xMutex2;
std::timed_mutex xTimedMutex;
std::recursive_mutex xRecMutex;

// Version1: no protection
/*
void increment(int times, int incVal) {
  while (times--) {
    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
    x += incVal;
  }
}
*/

// Version2: use naked lock(), unlock()
/*
void increment(int times, int incVal) {
  while (times--) {
    xMutex.lock();
    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
    x += incVal;
    xMutex.unlock();
  }
}
*/

// Version 3: use naked try_lock(), unlock()
/*
void increment(int times, int incVal) {
  while (times--) {
    while (!xMutex.try_lock()) {
      ;
      std::cout << "[" << std::this_thread::get_id() << "] try_lock()" << std::endl;
    }

    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
    x += incVal;
    xMutex.unlock();
  }
}
*/

// Version 4: timed_mutex
/*
void increment(int times, int incVal) {
  using namespace std::chrono_literals;

  while (times--) {
    // Blocks for the duration, then returns
    while (!xTimedMutex.try_lock_for(std::chrono::duration(0.01ms))) {
      ;
      std::cout << "[" << std::this_thread::get_id() << "] try_lock()" << std::endl;
    }

    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
    x += incVal;
    xTimedMutex.unlock();
  }
}
*/

// Version 5: use recursive lock
/*
void increment(int times, int incVal) {
  int nTimes = times;

  while (nTimes--) {
    // Can lock as many times
    xRecMutex.lock();
    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
    x += incVal;
  }

  // ... but must match number of unlocks
  while (times--)
    xRecMutex.unlock();
}
*/

// Version 6: use lock_guard
/*
void increment(int times, int incVal) {
  while (times--) {
    // std::mutex
    //std::lock_guard<std::mutex> lock{xMutex};

    // std::recursive_mutex
    std::lock_guard<std::recursive_mutex> lock{xRecMutex};

    x += incVal;
    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
  }
}
*/

// Version 7: use unique_lock
/*
void increment(int times, int incVal) {
  while (times--) {
    std::unique_lock<std::mutex> lock{xMutex};
    //std::unique_lock<std::recursive_mutex> lock{xRecMutex};

    x += incVal;
    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
  }
}
*/

// Version 8: use unique_lock with defer_lock
/*
void increment(int times, int incVal) {
  while (times--) {
    std::unique_lock<std::mutex> lock{xMutex, std::defer_lock};
    //std::unique_lock<std::recursive_mutex> lock{xRecMutex, std::defer_lock};

    // explicit lock
    lock.lock();

    x += incVal;
    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
  } // implicit unlock
}
*/

// Version 9: use scoped_lock with std::mutex, std::recursive_mutex and deferred std::unique_lock
/*
void increment(int times, int incVal) {
  while (times--) {
    std::unique_lock<std::mutex> ulock{xMutex2, std::defer_lock};
    std::scoped_lock lock{xMutex, xRecMutex, ulock};

    x += incVal;
    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
  }
}
*/

// Version 10: use std::lock with xMutex, xRecMutex
void increment(int times, int incVal) {
  while (times--) {
    std::unique_lock<std::mutex> lock1{xMutex, std::defer_lock};
    std::unique_lock<std::recursive_mutex> lock2{xRecMutex, std::defer_lock};

    std::lock(lock1, lock2);

    x += incVal;
    std::cout << "[" << std::this_thread::get_id() << "] increments" << std::endl;
  }
}

int main() {
  std::cout << "[" << std::this_thread::get_id() << "] main started" << std::endl;

  int nThreads = 5;
  int incVal = 1;
  int increments = 3;

  std::vector<std::thread> threads;

  for (int i = 0; i < nThreads; i++) {
    threads.push_back(std::thread{increment, increments, incVal});
  }

  for (int i = 0; i < nThreads; i++) {
    threads[i].join();
  }

  if (x != nThreads * incVal * increments) {
    std::cout << "Concurrency FAILED! " << x << "!=" << nThreads * incVal * increments << std::endl;
  }

  std::cout << "[" << std::this_thread::get_id() << "] main ended" << std::endl;
  return 0;
}
