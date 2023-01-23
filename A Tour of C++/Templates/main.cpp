#include <iostream>

#include "parameterized_type.h"

// Parameterized sum algorithm
template<typename Container, typename Value>
Value mySum(const Container& c, Value v)
{
  for (Value val : c)
    v += val;

  return v;
}

int main()
{
  Vector<int> v(5);
  v[0] = 0;
  v[1] = 10;
  v[2] = 10;
  v[3] = 10;
  v[4] = 10;

  int acc = 0;
  int sum = mySum<Vector<int>, int>(v, acc);
  std::cout << "sum = " << sum << std::endl;

  return 0;
}
