#include <string>
#include <iostream>
#include <algorithm>

class is_uppercase
{
public:
  bool operator()(char c) const { return (c >= 'A') && (c <= 'Z'); };
};

int main()
{
  std::string name{"Mihai-Alin Sendre"};
  std::string surname{"Alin"};
  std::string family_name{"Sendre"};

  // string::find
  int pos = name.find(surname);
  if (pos != std::string::npos)
  {
    // string::replace
    name.replace(pos, surname.size(), "Alexandru");
    std::cout << "New name: " << name << std::endl;

    // string::find
    int family_name_pos = name.find(family_name);
    std::cout << "family_name_pos = " << family_name_pos << std::endl;
    std::cout << "name.length() = " << name.length() << std::endl;
 
    // string::susbtr 
    std::string given_name = name.substr(0, family_name_pos);
    std::cout << "Given name: " << given_name << std::endl;
  }

  // std::remove_if
  //auto it = std::remove_if(name.begin(), name.end(), [&](char c){ return c < 'a'; });
  auto it = std::remove_if(name.begin(), name.end(), is_uppercase());
  // string::erase 
  name.erase(it, name.end());
  std::cout << "Name after remove_if: " << name << std::endl;

  // string::insert
  int endre_pos = name.find("endre");
  name.insert(name.begin() + endre_pos, 'S');
  name.insert(name.begin() + endre_pos + sizeof("endre"), 'a');
  std::cout << "Name after insert: " << name << std::endl;

  return 0;
}
