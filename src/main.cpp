#include "block.h"
#include <iostream>

int main() {
  Block block(1, "Alice paying bobe 10 niggers", "0000abc");

  std::cout << "Index: " << block.index << std::endl;
  std::cout << "Timestamp: " << block.timestamp << std::endl;
  std::cout << "Data: " << block.data << std::endl;
  std::cout << "Prev_hash: " << block.prev_hash << std::endl;
  std::cout << "hash: " << block.hash << std::endl;

  block.data = "Alice paying bobe 10 nigger";
  std::cout << std::endl << "New Data: " << block.data << std::endl;
  std::cout << "Old Hash: " << block.hash << std::endl; // old hash
  std::cout << "New hash: " << block.calculate_hash() << std::endl;
  std::cout << (block.hash == block.calculate_hash() ? "SAME" : "Fake Nigga")
            << std::endl;

  return 0;
}
