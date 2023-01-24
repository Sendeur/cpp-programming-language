
#include <stdexcept>
#include <iostream>

template<typename T>
class Vector {
private:
  T* elem;
  int sz;

public:
  using value_type = T;

  Vector(int s);
  ~Vector() { delete[] elem; }

  T& operator[](int i);
  const T& operator[](int i) const;
  int size() const { return sz; }
};

template<typename T>
Vector<T>::Vector(int _sz)
{
  if (_sz < 0)
    throw std::invalid_argument("Negative size variable");

  elem = new T[_sz];
  sz = _sz;
}

template<typename T>
T& Vector<T>::operator[](int i)
{
  if ((i < 0) || (i >= sz))
    throw std::range_error("Index outside range");

  return elem[i];
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
  if ((i < 0) || (i >= sz))
    throw std::range_error("Index outside range");

  return elem[i];
}

// Need 4 for-range loops
template<typename T>
T* begin(Vector<T>& v)
{
  return (v.size() > 0) ? &v[0] : nullptr;
}

template<typename T>
const T* begin(const Vector<T>& v)
{
  return (v.size() > 0) ? &v[0] : nullptr;
}

template<typename T>
T* end(Vector<T>& v)
{
  return (v.size() > 0) ? (&v[0] + v.size()) : nullptr;
}

template<typename T>
const T* end(const Vector<T>& v)
{
  return (v.size() > 0) ? (&v[0] + v.size()) : nullptr;
}

// Alias
using IntVector = Vector<int>;

// As generic a function as possible
template<typename Container>
typename Container::value_type mySum(const Container& c)
{
  typename Container::value_type acc = 0;
  for (const typename Container::value_type& v : c)
    acc += v;

  return acc;
}

// Alias v2
template<typename T>
using ValueType = typename T::value_type;

template<typename Container>
ValueType<Container> newSum(const Container& c)
{
  ValueType<Container> acc = 0;

  for (const ValueType<Container>& v : c)
    acc += v;

  return acc;
}
//

int main()
{
  IntVector v(5);
  v[0] = 1;
  v[1] = 3;
  v[2] = 0;
  v[3] = 1;
  v[4] = 5;

  int sum = mySum(v);
  std::cout << "sum = " << sum << std::endl;

  int sum2 = newSum(v);
  std::cout << "sum2 = " << sum2 << std::endl;

  return 0;
}
