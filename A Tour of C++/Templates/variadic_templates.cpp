#include <iostream>
#include <string>

template<typename T>
void multiply(T& val)
{
  val = val * 3;
}

template<typename T, typename... Tail>
void multiply(T& head, Tail... tail)
{
  head = head * 3;
  multiply(tail...);
}

int main()
{
  int x = 3;
  double y = 4.3;
  char c = 'a';
  multiply(y, x, c);
  std::cout << "x = " << x << " y = " << y << " c = " << c << std::endl;
  
  return 0;
}
