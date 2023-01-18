class Vector
{
public:
  Vector(int sz);
  double& operator[](int i);
  int size() const;

private:
  double *elem;
  int sz;
};
