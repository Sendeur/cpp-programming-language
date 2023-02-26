#include <iostream>

#include <memory>
#include <string>

struct Person {
  std::string name;
  std::string surname;

  Person(const std::string& name, const std::string& surname) : name(name), surname(surname) {}
  ~Person() { std::cout << "~Person(" << name << ", " << surname << ")" << std::endl; }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
  os << "{";
  os << p.name;
  os << ", ";
  os << p.surname;
  os << "}";
  return os;
}

template<typename T>
class custom_deleter {
public:
  using value_type = T;

  void operator()(T* elem) {
    std::cout << "Custom deleter called" << std::endl;
    delete elem;
  }
};

void main_unique_ptr() {
  // Constructors
  std::unique_ptr<Person> uPtr{new Person("Alin", "Anca")};
  std::unique_ptr<Person, custom_deleter<Person>> uniquePtr{new Person("Anca", "Tudor")};

  // Destructor for Person(Alin, Anca) is called
  uPtr = nullptr;
  std::cout << "Pointer reassigned!" << std::endl;

  // Destroy existing Person & reassign
  uPtr.reset(new Person("Alin", "Dimake"));

  // Get underlying pointer --> constructor will get called twice! Once by unique_ptr, once by Person destructor!
  Person p = *(uPtr.get());
  std::cout << "*(uPtr.get()) = " << p << std::endl;

  // Check if there's any underlying pointer
  if (!uPtr)
    std::cout << "uPtr empty1!" << std::endl;

  // Release ownership of underlying pointer
  p = *(uPtr.release());
  std::cout << "Ownership released!" << std::endl;

  // Check if there's any underlying pointer
  if (!uPtr)
    std::cout << "uPtr empty2!" << std::endl;
}

int main() {
  //main_unique_ptr();

  return 0;
}
