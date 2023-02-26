#include <iostream>

#include <bitset>

template <unsigned long N>
void printbs(std::bitset<N> bs) {
  std::cout << "BitSet = " << bs << std::endl;
}

template <std::size_t N>
void bsinfo(std::bitset<N> bs) {
  std::cout << "any=" << bs.any() << " all= " << bs.all() << " none=" << bs.none() << " count=" << bs.count() << std::endl;
}

int main() {
  std::bitset<8> bs{127};
  printbs(bs);

  if (bs.test(3)) {
    std::cout << "bs.reset(3)" << std::endl;
    bs.reset(3);
  }

  if (!bs.test(7)) {
    std::cout << "bs.set(7)" << std::endl;
    bs.set(7);
  }
  printbs(bs);

  std::bitset<8>::reference ref = bs[5];
  if (ref) {
    std::cout << "bs[5] set" << std::endl;
  } else { 
    std::cout << "bs[5] not set" << std::endl;
  }

  ref.flip();
  std::cout << "flip bs[5]" << std::endl;
  bsinfo(bs);
  printbs(bs);

  std::bitset<8> nbs = ~bs;
  printbs(nbs);

  nbs |= bs;
  printbs(nbs);

  nbs.flip();
  printbs(nbs);

  unsigned long val = nbs.to_ulong();
  std::cout << "val = " << val << std::endl;

  return 0;
};
