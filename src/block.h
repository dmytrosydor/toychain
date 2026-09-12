#pragma once
#include <string>

struct Block {
  int index;             // номер блоку в ланцюгу
  long timestamp;        // час створення, в секундах з 1970
  std::string data;      // поки просто текст
  std::string prev_hash; // хеш попреднього блоку
  long nonce;            // лічильник для майнінгу ( поки просто так)
  std::string hash;      // хеш цього блоку

  Block(int index, const std::string &data, const std::string &prevhash);

  // рахує хеш з усіх полів ( крім самого hash)
  std::string calculate_hash() const;
};
