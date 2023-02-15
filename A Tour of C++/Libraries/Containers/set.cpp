#include <iostream>

#include <array>
#include <set>

template<typename Container>
bool contains(const Container& c, const typename Container::value_type& v)
{
  return c.find(v) != c.end();
}

template<typename Key, typename Compare>
void walk_multiset(const std::multiset<Key, Compare>& s)
{
  typename std::multiset<Key, Compare>::const_iterator it = s.begin();

  while (it != s.end())
  {
    std::cout << *it << ", ";
    it++;
  }
  std::cout << std::endl;
}

template<typename Key, typename Compare>
void walk_set(const std::set<Key, Compare>& s)
{
  typename std::set<Key, Compare>::const_iterator it = s.begin();

  while (it != s.end())
  {
    std::cout << *it << ", ";
    it++;
  }
  std::cout << std::endl;
}

struct Pair {
  int x;
  int y;

  Pair(int x, int y) : x(x), y(y) { std::cout << "Pair(int x, int y)" << std::endl; }

  Pair(const Pair& p) {
    std::cout << "Pair(const Pair& p)" << std::endl;
    x = p.x;
    y = p.y;
  }

  Pair(Pair&& p) {
    std::cout << "Pair(Pair&& p)" << std::endl;
    x = p.x;
    y = p.y;
  }

  bool operator<(const Pair& p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};

int main() {
  // Construct set from initializer list
  std::set<int, bool (*)(int, int)> s({5, 1, 3, 2, 10, 7}, [](int x, int y) { return x < y; });
  walk_set(s);

  std::array<int, 5> arr{100, 10, 20, 15, 5}; // Construct set from iterators
  std::set<int, bool (*)(int, int)> s2(arr.begin(), arr.end(),
    [](int x, int y)
    {
      return x > y;
    }
  );
  walk_set(s2);

  // Custom contains function
  bool res = contains(s, 10);
  std::cout << "contains(s, 10) = " << res << std::endl;

  // Insert
  auto [it, _] = s2.insert(110);
  std::cout << "Inserted 110" << std::endl;
  walk_set(s2);

  // Insert many
  s2.insert({120, 1});
  std::cout << "Inserted 120, 1" << std::endl;
  walk_set(s2);

  // Find out equal_range
  auto [it1, it2] = s2.equal_range(10);
  std::cout << "equal_range() => " << *it1 << ", " << *it2 << std::endl;

  std::set<Pair> ss;
  // Calls 
  //  Pair(int x, int y)
  //  Pair(Pair&& p)
  std::cout << "insert() " << std::endl;
  ss.insert(Pair(0, 1));

  // Calls
  //  Pair(int x, int y)
  std::cout << "emplace() " << std::endl;
  ss.emplace(0, 2);

  std::multiset<int> ms{4, 2, 1, 1, 100, 3};
  walk_multiset(ms);

  return 0;
}
