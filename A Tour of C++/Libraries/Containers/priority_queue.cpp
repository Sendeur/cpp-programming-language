#include <queue>

#include <iostream>
#include <string>
#include <vector>
#include <deque>

struct Person {
  int id;
  std::string name;

  Person(int id, const std::string& name) : id(id), name(name) {}
};

struct PersonCompare {
public:
  bool operator()(const Person& p1, const Person& p2) {
    return p1.id < p2.id;
  }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
  os << "Person(" << p.id << ", " << p.name << ")";
  return os;
}

int main() {
  // Version 1 => max_heap
  std::priority_queue<Person, std::vector<Person>, PersonCompare> pq;

  // Version 2 => min_heap (lambda + std::function)
  //std::priority_queue<Person, std::deque<Person>, std::function<bool(const Person&, const Person&)>> pq([](const Person& p1, const Person& p2) { return p1.id > p2.id; });

  auto top = [&]() {
    std::cout << "top() = " << pq.top() << std::endl;
  };
  auto push = [&](const Person& p) {
    std::cout << "push(" << p << ")" << std::endl;
    pq.push(p);
  };

  push({1, "A"});
  top();

  push({-1, "B"});
  top();

  push({3, "C"});
  top();

  pq.emplace(5, "D");
  top();


  return 0;
}
