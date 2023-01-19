#include <iostream>

class Container
{
public:
  virtual double& operator[](int i) = 0;
  virtual int size() const = 0;
  virtual ~Container();
};

class Vector_container : public Container
{
public:
  Vector_container(int sz);
  Vector_container(std::initializer_list<double> lst);
  ~Vector_container();

  double& operator[](int i);
  int size() const;

private:
  int sz;
  double *elem;
};
