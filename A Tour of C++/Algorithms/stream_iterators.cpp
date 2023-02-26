#include <iostream>
#include <fstream>

#include <string>
#include <vector>

void copy_files(const std::string& from, const std::string& to)
{
  // Open input stream
  std::ifstream src{from};
  std::istream_iterator<std::string> ii{src}; // input iterator for "from"
  std::istream_iterator<std::string> eof{}; // end of file input iterator

  std::vector<std::string> content{ii, eof}; // initialize vector from input

  std::ofstream dest{to}; // output stream
  std::ostream_iterator<std::string> oo{dest, "\n"}; // output iterator for stream

  // copy content to destination output_iterator (use it like any other iterator)
  std::copy(content.begin(), content.end(), oo);
}

int main()
{
  std::istream_iterator<std::string> ii{std::cin};
  std::istream_iterator<std::string> eof{};

  std::vector<std::string> vec{ii, eof};
  for (const std::string& s : vec)
    std::cout << s << ' ';
  std::cout << std::endl;

  return 0;
}
