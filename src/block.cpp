#include "block.h"
#include "sha256.h"

#include <ctime>

Block::Block(int index, const std::string &data, const std::string &prev_hash)
    : index(index), timestamp(std::time(nullptr)), data(data),
      prev_hash(prev_hash), nonce(0) {
  hash = calculate_hash();
}

std::string Block::calculate_hash() const {
  std::string content = std::to_string(index) + "|" +
                        std::to_string(timestamp) + "|" + data + prev_hash +
                        std::to_string(nonce);
  return sha256(content);
}
