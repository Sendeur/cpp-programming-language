#include <iostream>
#include <vector>

// function object
template<typename T>
class Less_than
{
private:
  const T value;

public:
  Less_than(T val);
  bool operator()(const T& val) const;
};

template<typename T>
Less_than<T>::Less_than(T val) : value(val) {}

template<typename T>
bool Less_than<T>::operator()(const T& val) const
{
  return val < value;
}

// function object
template<typename T>
class Multiply
{
private:
  const T multiplier;

public:
  Multiply(T multiplier) : multiplier(multiplier) {}
  void operator()(T& value) { value = value * multiplier; }
};

// for_all
template<typename T, typename Operation>
void for_all(std::vector<T>& v, Operation op)
{
  for (auto& val : v)
    op(val);
}

int main()
{
  Less_than<int> lt{42};
  
  if (lt(40))
  {
    std::cout << "40 < 42" << std::endl;
  }

  if (lt(44))
  {
    std::cout << "44 < 42" << std::endl;
  }
  else
  {
    std::cout << "!(44 < 42)" << std::endl;
  }


  Multiply<int> mul(3);
  int x = 3;
  mul(x);
  std::cout << "x = " << x << std::endl;

  std::cout << "After functor" << std::endl;
  // functor variant
  std::vector<int> v{1, 2, 3};
  for_all(v, Multiply(3));
  for (int i = 0; i < v.size(); i++)
    std::cout << "v[" << i << "] = " << v[i] << std::endl;

  std::cout << "After lambda" << std::endl;
  // lambda variant
  for_all(v, [](int& x) { x = x * 3; });
  for (int i = 0; i < v.size(); i++)
    std::cout << "v[" << i << "] = " << v[i] << std::endl;

  return 0;
}
