#include <iostream>
#include <array>

template<typename Container>
void print_all(const Container& c)
{
  for (typename Container::value_type elem : c)
    std::cout << elem << ", "; 
  std::cout << std::endl;
}

int main() {
  std::array<double, 5> fiveDoubles{1.0, 2.0, 3.0, 4.0, 5.0};
  print_all(fiveDoubles);

  // Fill-with-zeroes constructor
  std::array<int, 10> tenInts{0};
  print_all(tenInts);

  // Fill with two's
  tenInts.fill(2);
  std::cout << "fill with two's" << std::endl;
  print_all(tenInts);

  tenInts[2] = 5;
  std::cout << "tenInts[2] = 5" << std::endl;
  print_all(tenInts);



  return 0;
}
