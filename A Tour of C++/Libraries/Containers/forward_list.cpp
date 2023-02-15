#include <iostream>

#include <algorithm>
#include <string>
#include <forward_list>

struct Person {
  int id;
  std::string name;

  Person(int id, const std::string& name) : id(id), name(name) {}
};

bool operator<(const Person& p1, const Person& p2) {
  return p1.id < p2.id;
}

bool operator==(const Person& p1, const Person &p2) {
  return p1.id == p2.id && p1.name == p2.name;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
  os << "Person(" << p.id << ", " << p.name << "), ";
  return os;
}

template<typename Container>
void print(const Container& c)
{
  typename Container::const_iterator it = c.begin();

  while (it != c.end())
  {
    std::cout << *(it++) << ", ";
  }

  std::cout << std::endl;
}

int main() {
  std::forward_list<Person> li{
    {1, "Mihai-Alin"},
    {0, "Anca Tudor"},
    {10, "Iordache Bogdan"},
    {7, "Mihai Cacior"},
  };
  print(li);  

  // Get first element
  Person p = li.front();
  std::cout << "li.front() = " << p << std::endl;

  std::forward_list<Person>::iterator it;

  // Insert {5, "Marian"} at front
  it = li.before_begin();
  li.insert_after(it, {5, "Marian"});
  std::cout << "insert({5, Marian}) in front" << std::endl;
  print(li);  

  // Get first element again
  it = li.begin();
  std::cout << "li.front() = " << *it << std::endl;

  // Find Iordache Bogdan
  it = std::find<decltype(it), Person>(li.begin(), li.end(), {10, "Iordache Bogdan"});
  if (it != li.end())
    std::cout << "found Iordache Bogdan" << std::endl;
  else
    std::cout << "NOT found Iordache Bogdan" << std::endl;

  // Remove {10, "Iordache Bogdan"}
  std::forward_list<Person>::iterator prev = li.end();

  for (it = li.begin(); it != li.end(); it++) {
    if (it->id == 10 && it->name == "Iordache Bogdan")
      break;

    prev = it;
  }

  if (prev != li.end() && it != li.end())
  {
    li.erase_after(prev);
    std::cout << "erased Iordache Bogdan" << std::endl;
  } else {
    std::cout << "not erased Iordache Bogdan" << std::endl;
  }
  print(li);  
  
  // Emplace {9, "Neakju"} after {0, "Anca Tudor"}
  it = std::find_if(li.begin(), li.end(),
    [](const Person& p)
    {
      return p.id == 0 && p.name == "Anca Tudor";
    }
  );
  li.emplace_after(it, 9, "Neakju");
  std::cout << "Emplaced {9, Neakju} after Anca Tudor" << std::endl;
  print(li);

  // Remove all id<7
  li.remove_if([](const Person& p) { return p.id < 7; });
  std::cout << "remove_if(id < 7)" << std::endl;
  print(li);

  // Sort inverse
  li.sort([](const Person& p1, const Person& p2) { return p1.id < p2.id; });
  std::cout << "sort()" << std::endl;
  print(li);

  // Reverse
  li.reverse();
  std::cout << "reverse()" << std::endl;
  print(li);

  return 0;
}
