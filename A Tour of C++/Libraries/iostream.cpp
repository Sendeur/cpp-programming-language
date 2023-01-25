#include <iostream>
#include <string>

class Person
{
private:
  std::string family_name;
  std::string given_name;

public:
  Person() : family_name(), given_name() {}
  Person(std::string family_name, std::string given_name) : family_name(family_name), given_name(given_name) {}

  friend std::ostream& operator<<(std::ostream& os, const Person& p);
  friend std::istream& operator>>(std::istream& is, Person& p);
};

// User-defined output
std::ostream& operator<<(std::ostream& os, const Person& p)
{
  return os << "Given name: " << p.given_name << std::endl << "Family name: " << p.family_name << std::endl;
}

// User-defined input
std::istream& operator>>(std::istream& is, Person& p)
{
  std::cout << "Please enter the family name: ";
  std::getline(is, p.family_name);
  //is >> p.family_name;
  std::cout << "Please enter the given name: ";
  std::getline(is, p.given_name);
  //is >> p.given_name;
  return is;
}
// The istream& reference can be used to test if the operation succeeded.
// if (is >> c) means "Did we succeed at reading from is into c?"

int main()
{
  Person alin("Sendre", "Mihai-Alin");
  std::cout << alin;

  std::cin >> alin;
  std::cout << alin;

  return 0;
}
