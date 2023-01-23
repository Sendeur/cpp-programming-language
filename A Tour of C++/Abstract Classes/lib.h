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
  Vector_container();
  Vector_container(int sz);
  Vector_container(std::initializer_list<double> lst);
  Vector_container(const Vector_container& vec);
  Vector_container(Vector_container&& vec);

  ~Vector_container();

  Vector_container& operator=(Vector_container&& vec);
  Vector_container& operator=(const Vector_container& vec);
  double& operator[](int i);

  int size() const;

private:
  int sz;
  double *elem;
};
