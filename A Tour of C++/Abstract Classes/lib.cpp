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

Vector_container::Vector_container() : sz(0), elem(nullptr)
{
  std::cout << "Vector_container()" << std::endl;
}

Vector_container::Vector_container(int _sz)
{
  std::cout << "Vector_container(" << sz << ")" << std::endl;
  if (_sz < 0)
  {
    throw std::length_error("Vector_container size cannot be negative");
  }

  sz = _sz;
  elem = new double[_sz];
}

Vector_container::Vector_container(std::initializer_list<double> lst) : Vector_container(lst.size())
{
  std::cout << "Vector_container(initializer_lst)" << std::endl;
  std::copy(lst.begin(), lst.end(), elem);
}

// Copy constructor
Vector_container::Vector_container(const Vector_container& vec)
{
  std::cout << "Vector_container(const Vector_container& vec)" << std::endl;

  // Move elements across
  double *p = new double[vec.sz]; for (int i = 0; i < vec.sz; i++)
    p[i] = vec.elem[i];

  sz = vec.sz;
  elem = p;
}

// Move constructor
Vector_container::Vector_container(Vector_container&& vec)
{
  std::cout << "Vector_container(Vector_container&& vec)" << std::endl;

  // Move elements across
  double *p = new double[vec.sz]; for (int i = 0; i < vec.sz; i++)
    p[i] = vec.elem[i];

  sz = vec.sz;
  elem = p;

  // Deallocate memory for vec
  delete[] vec.elem;
  vec.sz = 0;
  vec.elem = nullptr;
}

Vector_container::~Vector_container()
{
  std::cout << "~Vector_container()" << std::endl;
  delete[] elem;
}

// Copy assignment
Vector_container& Vector_container::operator=(const Vector_container& vec)
{
  std::cout << "operator=(const Vector_container& vec)" << std::endl;

  // Move elements across
  double *p = new double[vec.sz]; for (int i = 0; i < vec.sz; i++)
    p[i] = vec.elem[i];

  delete[] elem;
  elem = p;
  sz = vec.sz;
  return *this;
}

// Move assignment
Vector_container& Vector_container::operator=(Vector_container&& vec)
{
  std::cout << "operator=(Vector_container&& vec)" << std::endl;

  // Move elements across
  double *p = new double[vec.sz]; for (int i = 0; i < vec.sz; i++)
    p[i] = vec.elem[i];

  // Redo this
  delete[] elem;
  elem = p;
  sz = vec.sz;

  // Destroy vec
  vec.sz = 0;
  delete[] vec.elem;
  vec.elem = nullptr;
  return *this;
}

int Vector_container::size() const
{
  return sz;
}

double& Vector_container::operator[](int i)
{
  if ( (i < 0) || (i >= sz) )
  {
    throw std::out_of_range("Accessing Vector_container object outside its bounds");
  }

  return elem[i];
}
