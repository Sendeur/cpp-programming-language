#include <iostream>

// Doubly-linked list
#include <list>
#include <string>
#include <algorithm>

// Person
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct Person
{
  std::string name{};
  std::string surname{};

  Person(const std::string& name, const std::string& surname) : name(name), surname(surname) {}
};

class RightPerson
{
  Person person;

public:
  RightPerson(const Person& person) : person(person) {}

  bool operator()(const Person& p) { return p.name == person.name && p.surname == person.surname; }
};

std::ostream& operator<<(std::ostream& os, const Person& person)
{
  os << "(";
  os << person.name;
  os << ",";
  os << person.surname;
  os << ")";
  return os;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename Container>
void print_list(const Container& c)
{
  for (typename Container::value_type elem : c)
  {
    std::cout << elem << ", ";
  }

  std::cout << std::endl;
}

int main()
{
  std::list<Person> myList = {
    {"Alin", "Sendre"},
    {"Alin", "Dimache"},
    {"Anca", "Tudor"}
  };
  print_list(myList);

  std::list<Person>::iterator it = myList.begin();

  for (; it != myList.end(); it++)
  {
    std::cout << "name=" << it->name << ", surname=" << it->surname << std::endl;
  }


  // find Dimache
  //std::list<Person>::iterator pDimache = std::find_if(myList.begin(), myList.end(), RightPerson({"Alin", "Dimache"}));
  std::list<Person>::iterator pDimache = std::find_if(myList.begin(), myList.end(), [&](const Person& p) { return p.name == "Alin" && p.surname == "Dimache"; });
  if (pDimache != myList.end())
  {
    std::cout << "Found Dimache!" << std::endl;
  }

  // insert after Dimache
  std::advance(pDimache, 1); // next()
  myList.insert(pDimache, {"George", "Muraru"});
  print_list(myList);

  // insert before Dimache
  pDimache = std::find_if(myList.begin(), myList.end(), [&](const Person& p) { return p.name == "Alin" && p.surname == "Dimache"; });
  myList.insert(pDimache, {"Anca", "Barbu"});
  print_list(myList);

  // find George Muraru
  std::list<Person>::iterator pMuraru = std::find_if(myList.begin(), myList.end(), [&](const Person& p) { return p.name == "George" && p.surname == "Muraru"; });
  // Remove him
  myList.erase(pMuraru);
  print_list(myList);

  return 0;
}
