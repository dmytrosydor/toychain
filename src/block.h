#pragma once
#include "transaction.h"
#include <string>
#include <vector>

struct Block {
  int index;                             // номер блоку в ланцюгу
  long timestamp;                        // час створення, в секундах з 1970
  std::vector<Transaction> transactions; // замість data
  std::string merkle_root;               // Відбиток усіх транзакцій
  std::string prev_hash;                 // хеш попреднього блоку
  long nonce;       // лічильник для майнінгу ( поки просто так)
  std::string hash; // хеш цього блоку

  Block(int index, const std::vector<Transaction> &transactions,
        const std::string &prevhash);

  // рахує хеш з усіх полів ( крім самого hash)
  std::string calculate_hash() const;

  // Підбирає nonce поки hash нге почнеться з difficutlty нулів
  void mine(int difficulty);
};
