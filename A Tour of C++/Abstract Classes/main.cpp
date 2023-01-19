#include "lib.h"

void print_container(Container& c)
{
  for (int i = 0; i < c.size(); i++)
  {
    std::cout << "c[" << i << "] = " << c[i] << std::endl;
  }
}

int main()
{
  Vector_container v({1, 2, 3, 4, 5});
  print_container(v);

  Container& v1 = v;
  print_container(v1);

  Container* v2 = &v;
  print_container(*v2);

  return 0;
}
