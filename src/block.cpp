#include "block.h"
#include "merkle.h"
#include "sha256.h"
#include <ctime>

Block::Block(int index, const std::vector<Transaction> &transactions,
             const std::string &prev_hash)
    : index(index), timestamp(std::time(nullptr)), transactions(transactions),
      merkle_root(::merkle_root(transactions)), prev_hash(prev_hash), nonce(0) {
  hash = calculate_hash();
}

std::string Block::calculate_hash() const {
  std::string content = std::to_string(index) + "|" +
                        std::to_string(timestamp) + "|" + merkle_root +
                        prev_hash + std::to_string(nonce);
  return sha256(content);
}

void Block::mine(int difficulty) {
  std::string target = std::string(difficulty, '0');
  while (hash.substr(0, difficulty) != target) {
    nonce++;
    hash = calculate_hash();
  }
}
