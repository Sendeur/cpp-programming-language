#include <iostream>
#include <chrono>
#include <vector>

#define LEN 1000000

int main()
{
  std::vector<int> vec(LEN, 0);

  auto T1 = std::chrono::high_resolution_clock::now();
  for (auto& val : vec)
  {
    
  }
  auto T2 = std::chrono::high_resolution_clock::now();
  auto T2_T1 = std::chrono::duration_cast<std::chrono::microseconds>(T2 - T1);
  std::cout << "Reference assignment: " << T2_T1.count() << std::endl;

  auto T3 = std::chrono::high_resolution_clock::now();
  for (auto val : vec)
  {

  }
  auto T4 = std::chrono::high_resolution_clock::now();
  auto T4_T3 = std::chrono::duration_cast<std::chrono::microseconds>(T4 - T3);
  std::cout << "Copy assignment: " << T4_T3.count() << std::endl;

  return 0;
}
