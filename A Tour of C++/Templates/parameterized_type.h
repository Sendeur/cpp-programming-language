
#include <stdexcept>

template<typename T>
class Vector {

private:
  T* elem;
  int sz;

public:
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

