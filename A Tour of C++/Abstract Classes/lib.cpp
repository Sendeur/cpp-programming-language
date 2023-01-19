#include "lib.h"

///////////////
// Container //
///////////////

Container::~Container()
{
  std::cout << "~Container()" << std::endl;
}

//////////////////////
// Vector_container //
//////////////////////

Vector_container::Vector_container(int sz)
{
  std::cout << "Vector_container(" << sz << ")" << std::endl;
  if (sz < 0)
  {
    throw std::length_error("Vector_container size cannot be negative");
  }

  this->sz =sz;
  this->elem = new double[sz];
}

Vector_container::Vector_container(std::initializer_list<double> lst) : Vector_container(lst.size())
{
  std::cout << "Vector_container(initializer_lst)" << std::endl;
  std::copy(lst.begin(), lst.end(), this->elem);
}

Vector_container::~Vector_container()
{
  std::cout << "~Vector_container()" << std::endl;
}

int Vector_container::size() const
{
  return this->sz;
}

double& Vector_container::operator[](int i)
{
  if ( (i < 0) || (i >= this->sz) )
  {
    throw std::out_of_range("Accessing Vector_container object outside its bounds");
  }

  return this->elem[i];
}
