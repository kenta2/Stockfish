#include "types.h"
#include "misc.h"
#include <fstream>

Key Key::rand(PRNG* rng){
  Key k;
  k.key = rng->rand<uint64_t>();
  return k;
}

std::ostream& operator<<(std::ostream& os, const Key& k) {
  os << k.key;
  return os;
}
