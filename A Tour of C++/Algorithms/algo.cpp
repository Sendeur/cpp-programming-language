#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <list> 
#include <array> 

std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p)
{
  os << "{";
  os << p.first;
  os << ", ";
  os << p.second;
  os << "}, ";
  return os;
}

template <typename Container> 
void print_container(const Container& c) 
{ 
  for (const auto& elem : c) 
  { 
    std::cout << elem << ", "; 
  }
  std::cout << std::endl;
}

// templates + using
template<typename C>
using Iterator = typename C::iterator;

// Returns vector of iterators
template<typename C, typename V>
std::vector<Iterator<C>> find_all(C& c, V value)
{
  std::vector<Iterator<C>> res;

  for (Iterator<C> it = c.begin(); it != c.end(); it++)
  {
    if (*it == value)
      res.push_back(it);
  }

  return res;
}

std::string reverse_string(const std::string& s)
{
  std::string res;

  // Fails: no push_front for array
  //std::copy(s.begin(), s.end(), std::front_inserter(res));

  return res;
}

template<typename T>
std::vector<T> reverse_vector(const std::vector<T>& vec)
{
  std::vector<T> res;

  // Fails: no push_front for vector
  //std::copy(vec.begin(), vec.end(), std::front_inserter(res));

  return res; 
}

template<typename T>
std::list<T> reverse_list(const std::list<T>& l)
{
  std::list<T> res;

  std::copy(l.begin(), l.end(), std::front_inserter(res));

  return res; 
}

std::string copy_if_uppercase(const std::string& s)
{
  std::string res;

  std::copy_if(s.begin(), s.end(), std::back_inserter(res),
    [](char c) {
      return (c >= 'A' && c <= 'Z') || (c == ' ');
    }
  );

  return res;
}

std::string strip_whitespaces(const std::string& s)
{
  std::string res;

  std::unique_copy(s.begin(), s.end(), std::back_inserter(res),
    [](char c1, char c2) {
      // Returns "consecutive elements are equal" only for whitespaces.
      // This strips all consecutive whitespaces.
      return c1 == ' ' && c2 == ' ';
    }
  );

  return res;
}


int main()
{
  std::vector<int> v1{3, 4, 3, 3, 3, 3, 3, 3, 5, 7, 5, 6, 5};
  std::vector<int> v2{8, 9, 11, 10, 0, 0, 0, 0};

  std::vector<int>::iterator it = v2.begin();
  std::advance(it, 1);

  // unique_copy
  std::unique_copy(v1.begin(), v1.end(), it);
  print_container(v2);

  v2 = {8, 9, 10, 11};
  // back_inserter
  std::unique_copy(v1.begin(), v1.end(), std::back_inserter(v2));
  std::sort(v2.begin(), v2.end());
  print_container(v2);

  std::list<int> l2 = {2, 2, 2, 2};
  // front_inserter
  std::unique_copy(v1.begin(), v1.end(), std::front_inserter(l2));
  print_container(l2);

  std::string str = "Bebe este mic si blegut";
  // iterators point to all occurences of 'e' in string
  std::vector<std::string::iterator> iterators = find_all(str, 'e');
  for (auto it : iterators)
    *it = 'v';
  std::cout << "str = " << str << std::endl;

  std::string lotsOfWS = "Bebe   este mic  si   placut      la            labutz";
  std::cout << "lotsOfWS = " << lotsOfWS << std::endl;

  std::string strippedStr = strip_whitespaces(lotsOfWS);
  std::cout << "strippedStr = " << strippedStr << std::endl;

  std::list<int> l{1, 2, 3, 4, 5};
  std::list<int> revL= reverse_list(l);
  print_container(revL);

  std::string lowercaseUppercaseStr = "bebeBEBE esteESTE micMIC rAU";
  std::string uppercaseStr = copy_if_uppercase(lowercaseUppercaseStr);
  std::cout << "uppercaseStr = " << uppercaseStr << std::endl;

  std::vector<std::pair<int, int>> vec1{ {0, 1}, {0, 2}, {3, -100}, {6, -300}, {10, 10} };
  std::vector<std::pair<int, int>> vec2{ {-2, 0}, {1, 3}, {2, 3}, {3, 1}, {5, 1}, {5, 10}, {10, 100}, {10, 200}, {11, 1} };
  std::vector<std::pair<int, int>> sortedPairs;

  std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(sortedPairs),
    [&](const std::pair<int, int>& p1, const std::pair<int, int>& p2)
    {
      if (p1.first < p2.first) {
        return true;
      } else if (p1.first == p2.first) {
        return p1.second < p2.second;
      }
      return false;
    }
  );
  print_container(sortedPairs);

  std::array<int, 15> arr{1, 1, 2, 3, 10, 10, 11, 12, 12, 14, 14, 14, 14, 17, 20};
  auto res = std::equal_range(arr.begin(), arr.end(), 14,
    [](int x, int y) {
      return x < y;
    }
  ); 
  std::cout << "equal_range => " << res.first - arr.begin() << ", " << res.second - arr.begin() << std::endl;



  return 0;
}
