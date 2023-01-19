#include <iostream>

#include "Vector.h"

int main()
{
  std::cout << "======================================" << std::endl;
  std::cout << "default constructor example" << std::endl;
  {
    Vector v(10);
    v.print();
  }
  std::cout << "======================================" << std::endl;

  std::cout << "initializer_list example" << std::endl;
  {
    Vector v({1, 2, 3, 4});
    v.print();
  }
  std::cout << "======================================" << std::endl;

  return 0;
}
