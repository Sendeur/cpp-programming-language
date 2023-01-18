#include <iostream>
#include "Vector.h"

//////////////////////////////////
// Vector with struct
struct Vector1 {
  int sz;
  double *elem;
};

void init_Vector(Vector1& v, int sz)
{
  v.elem = new double[sz];
  v.sz = sz;
}

void deinit_Vector(Vector1& v)
{
  delete[] v.elem;
}
//////////////////////////////////


int main()
{
  Vector v(3);
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  std::cout << v[0] << std::endl;
  std::cout << v[1] << std::endl;
  std::cout << v[2] << std::endl;

  try
  {
    std::cout << v[3] << std::endl;
  }
  catch (std::out_of_range)
  {
    std::cout << "Exception caught!" << std::endl;
  }


  return 0;
}
