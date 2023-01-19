#include <iostream>

class Vector
{
public:
  Vector(int sz);
  Vector(std::initializer_list<double> lst);
  ~Vector();

  double& operator[](int i);
  int size() const;
  void print() const;

private:
  double *elem;
  int sz;
};
