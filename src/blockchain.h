#pragma once
#include "block.h"
#include <string>
#include <vector>

class Blockchain {
public:
  Blockchain();

  void add_block(const std::string &data);
  bool is_valid() const;
  const Block &last_block() const;
  void print() const;
  size_t lenght() const;

  std::vector<Block> blocks;
};
