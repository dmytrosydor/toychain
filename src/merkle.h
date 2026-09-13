#pragma once
#include "transaction.h"
#include <string>
#include <vector>

// Обчислює корінь дерева Меркла для списку транзакцій
std::string merkle_root(const std::vector<Transaction> &transactions);
