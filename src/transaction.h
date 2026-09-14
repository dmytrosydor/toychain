#pragma once
#include "wallet.h"
#include <string>

struct Transaction {
  std::string from;      // Адреса відправника
  std::string to;        // Адреса отримувача
  long long amount;      // Сума в монетах (ціле число)
  std::string signature; // Підпис

  // Рядок з полів які захищає підпис - без signature
  std::string to_string() const;

  // Хеш транзакції - її унікальний ідентифікатор
  std::string hash() const;


  void sign(const Wallet& wallet);

  bool is_valid() const;
};
