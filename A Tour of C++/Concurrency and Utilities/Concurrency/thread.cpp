#include <iostream>
#include <vector>
#include <numeric>

#include <thread>
#include <mutex>
#include <functional>

struct F {
public:
  F(const std::vector<int>& vec, int* output) : vec(vec), output(output) {}

  void operator()(int x) {
    std::cout << "(int x)" << std::endl;    
    sum();
  }

  void operator()(int& x) {
    std::cout << "(int& x)" << std::endl;    
    sum();
  }

  void operator()(const int& x) {
    std::cout << "(const int& x)" << std::endl;    
    sum();
  }

  void sum() {
    *output = std::accumulate(vec.begin(), vec.end(), 0,
      [](int x, int y)
      {
        return x + y;
      }
    );
  }

  const std::vector<int>& vec;
  int* output;  
};

void func(int x) {
  std::this_thread::get_id();
  std::cout << "func(int x)" << std::endl;
  x += 1;
}

void func(int& x) {
  std::cout << "func(int& x)" << std::endl;
  x += 1;
}

void func(const int& x) {
  std::cout << "func(const int& x)" << std::endl;
  //x += 1;
}

void func() {
  std::cout << "fund()" << std::endl;
}

int main() {
  int x = 0;

  int *output = new int;
  std::vector<int> vec{1, 2, 3, 4, 5};
  F obj{vec, output};

  void (*funcptr1)() = func;
  std::thread t1(funcptr1);
  t1.join();

  void (*funcptr2)(int) = func;
  std::thread t2(funcptr2, x);
  t2.join();
  std::cout << "x = " << x << " thread_id = " << t2.get_id() << std::endl;

  void (*funcptr3)(int&) = func;
  std::thread t3(funcptr3, std::ref(x));
  t3.join();
  std::cout << "x = " << x << " thread_id = " << t3.get_id() << std::endl;

  void (*funcptr4)(const int&) = func;
  std::thread t4(funcptr4, std::cref(x));
  t4.join();
  std::cout << "x = " << x << std::endl;

  return 0;
}
