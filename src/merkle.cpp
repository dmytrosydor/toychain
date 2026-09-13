#include "merkle.h"
#include "sha256.h"

std::string merkle_root(const std::vector<Transaction> &transactions) {
  if (transactions.empty()) {
    return sha256("");
  }
  std::vector<std::string> level;
  for (const Transaction &tr : transactions) {
    level.push_back(tr.hash());
  }

  while (level.size() > 1) {
    if (level.size() % 2 != 0) {
      level.push_back(level.back());
    }
    std::vector<std::string> next;
    for (size_t i = 0; i < level.size(); i += 2) {
      next.push_back(sha256(level[i] + level[i + 1]));
    }
    level = next;
  }
  return level[0];
}
