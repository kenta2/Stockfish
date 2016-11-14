#include "types.h"
#include "misc.h"
#include <fstream>

Key Key::rand(PRNG* rng1, PRNG* rng2){
  Key k;
  k.key1 = rng1->rand<uint64_t>();
  // we use two independent random number generators, instead of
  // calling one rng twice in order to preserve identical behavior
  // with the original narrow key.
  k.key2 = rng2->rand<uint64_t>();
  return k;
}

std::ostream& operator<<(std::ostream& os, const Key& k) {
  os << k.key1 << " " << k.key2;
  return os;
}
