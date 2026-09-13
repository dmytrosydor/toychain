#include "blockchain.h"
#include <chrono>
#include <iostream>

int main() {
  Blockchain chain(3);
  chain.add_transaction({"alice", "bob", 10, ""});
  chain.add_transaction({"bob", "carol", 5, ""});
  chain.mine_pending("miner");
  chain.add_transaction({"carol", "alice", 2, ""});
  chain.mine_pending("miner");
  chain.print();
  std::cout << "Валідний? " << (chain.is_valid() ? "так" : "НІ") << "\n\n";
  // Атака: міняємо суму в уже змайненому блоці.
  chain.blocks[1].transactions[0].amount = 1000;
  std::cout << "Після підробки валідний? " << (chain.is_valid() ? "так" : "НІ")
            << "\n";
  return 0;
}
