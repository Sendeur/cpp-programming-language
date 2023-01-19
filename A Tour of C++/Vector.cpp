#include "Vector.h"
#include <iostream>

// Specify the class invariant
Vector::Vector(int sz) : elem(new double[sz]), sz(sz)
{
  std::cout << "Vector(" << sz << ")" << std::endl;
  if (sz < 0)
  {
    throw std::length_error("Vector constructor size");
  }

  this->elem = new double[sz];
  this->sz = sz;
}

Vector::Vector(std::initializer_list<double> lst) : Vector(lst.size())
{
  std::cout << "Vector(initializer_list)" << std::endl;
  std::copy(lst.begin(), lst.end(), this->elem);
}

Vector::~Vector()
{
  std::cout << "~Vector()" << std::endl;
  delete[] this->elem;
}

double& Vector::operator[](int i)
{
  if (i < 0)
  {
    throw std::out_of_range("Vector::operator[]");
  }

  if (i >= this->sz)
  {
    throw std::out_of_range("Vector::operator[]");
  }

  return this->elem[i];
}

int Vector::size() const
{
  return this->sz;
}

void Vector::print() const
{
  for (int i = 0; i < this->sz; i++)
  {
    std::cout << this->elem[i] << std::endl;
  }
}
