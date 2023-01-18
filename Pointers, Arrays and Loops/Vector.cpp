#include "Vector.h"
#include <iostream>

// Specify the class invariant
Vector::Vector(int sz) : elem(new double[sz]), sz(sz)
{
  if (sz < 0)
  {
    throw std::length_error("Vector constructor size");
  }

  this->elem = new double[sz];
  this->sz = sz;
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
