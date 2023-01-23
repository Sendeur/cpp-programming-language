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
  //print_container(v);

  Container& c1 = v;
  //print_container(c1);

  Container* c2 = &v;
  //print_container(*c2);

  Vector_container v1(std::move(v));
  printf("After move\n");

  print_container(v);
  printf("After print\n");

  return 0;
}
