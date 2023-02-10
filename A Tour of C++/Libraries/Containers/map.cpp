#include <iostream>

#include <string>
#include <map>

struct Person
{
private:
  std::string name{};
  std::string surname{};

public:
  Person(const std::string& name, const std::string& surname) : name(name), surname(surname) {}

  friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
  os << "{";
  os << p.name << ", ";
  os << p.surname;
  os << "}";
  return os;
}

void print_map(const std::map<int, Person>& m)
{
  /*
  std::cout << "C++98" << std::endl;
  std::cout << std::endl;
  // C++98
  for (std::map<int, Person>::const_iterator it = m.begin(); it != m.end(); it++)
  {
    std::cout << "myMap[" << it->first << "] = " << it->second << std::endl;
  }
  */

  /*
  std::cout << std::endl;
  std::cout << "C++11" << std::endl;
  // C++11
  for (const std::pair<int, Person>& p : m)
  {
    std::cout << "myMap[" << p.first << "] = " << p.second << std::endl;
  }
  */

  // C++17
  for (const auto& [key, value] : m)
  {
    std::cout << "myMap[" << key << "] = " << value << std::endl;
  }
}

int main()
{
  std::map<int, Person> myMap{
    {1, {"Alin", "Dimache"}},
    {2, {"Alin", "Sendre"}}
  };
  print_map(myMap);

  std::map<int, Person>::iterator pMap;
  // find
  pMap = myMap.find(1);
  if (pMap != myMap.end())
  {
    std::cout << "found: " << pMap->second << std::endl;
  }

  // insert using iterator
  pMap->second = {"Anca", "Tudor"};
  print_map(myMap);

  std::cout << std::endl;
  // insert using function
  myMap.insert({1, {"Alin", "Dimake"}});
  // insert_or_assign
  myMap.insert_or_assign<Person>(1, {"Mircea", "Diaconu"});
  print_map(myMap);

  // erase by iterator
  pMap = myMap.find(1);
  if (pMap != myMap.end())
  {
    myMap.erase(pMap);
  }
  std::cout << std::endl;
  print_map(myMap);

  // erase by key
  myMap.erase(2);
  print_map(myMap);

  return 0;
}

