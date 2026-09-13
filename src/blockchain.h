#pragma once
#include "block.h"
#include "transaction.h"
#include <string>
#include <vector>

class Blockchain {
public:
  Blockchain();
  explicit Blockchain(int difficulty);

  void add_transaction(const Transaction &tx);
  void mine_pending(const std::string &miner_address);

  bool is_valid() const;
  const Block &last_block() const;
  void print() const;

  std::vector<Block> blocks;
  std::vector<Transaction> pending;
  int difficulty;

  static const long long MINING_REWARD = 50;
};
