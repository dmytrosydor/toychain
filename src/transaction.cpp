#include "transaction.h"
#include "sha256.h"

std::string Transaction::to_string() const {
  return from + " -> " + to + "\t| Amount: " + std::to_string(amount);
}

std::string Transaction::hash() const { return sha256(to_string()); }
