#include <vector>
#include <string>
#include <iostream>

struct Person
{
  std::string name{}; //in-class member initializer
  std::string surname{}; //in-class member initializer

  Person(std::string name, std::string surname) : name(name), surname(surname) {}
};

std::ostream& operator<<(std::ostream& os, const Person& person)
{
  return os << person.name << ", " << person.surname << std::endl;
}

template<typename T>
class Vector : public std::vector<T>
{
public:
  // inherit vector constructors in scope
  using std::vector<T>::vector;
  // inherit 'at' function in scope
  using std::vector<T>::at;

  T& operator[](int i)
  {
    return at(i);
  }

  const T& operator[](int i) const
  {
    return at(i);
  }
};

int main()
{
  std::vector<Person> persons{ {"Anca", "Tudor"}, {"Mihai", "Sendre"} };
  
  for (const Person& person : persons)
  {
    std::cout << person;
  }

  Vector<Person> pers{ {"Anca", "Tudor"}, {"Mihai", "Sendre"} };
  Person p = pers[2];

  return 0;
}
