#include "blockchain.h"
#include <iostream>

Blockchain::Blockchain() { blocks.push_back(Block(0, "Genesis -> none", "1")); }

const Block &Blockchain::last_block() const { return blocks.back(); }

void Blockchain::add_block(const std::string &data) {
  blocks.push_back(Block(blocks.size(), data, last_block().hash));
}

bool Blockchain::is_valid() const {
  for (unsigned long i = 1; i < blocks.size(); ++i) {
    const Block *previous = &blocks[i - 1];
    const Block *current = &blocks[i];

    if (current->hash != current->calculate_hash()) {
      std::cout << "Block: " << current->index << ": hash not matching";
      return false;
    }
    if (current->prev_hash != previous->hash) {
      std::cout << "Block: " << previous->index << ": prev_hash not matching";
      return false;
    }
  }
  return true;
}

void Blockchain::print() const {
  for (const Block &a : blocks) {
    std::cout << "Number: " << a.index << "\tData: " << a.data
              << "\tHash(16): " << a.hash.substr(0, 16)
              << "\tPrevHash: " << a.prev_hash.substr(0, 16) << std::endl;
  }
}

size_t Blockchain::lenght() const { return blocks.size(); }
