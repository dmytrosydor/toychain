#include "blockchain.h"
#include "merkle.h"
#include <iostream>

Blockchain::Blockchain(int difficulty) : difficulty(difficulty) {
  Block genesis(0, {}, "0");
  genesis.mine(difficulty);
  blocks.push_back(genesis);
}

const Block &Blockchain::last_block() const { return blocks.back(); }

void Blockchain::add_transaction(const Transaction &tx) {
  pending.push_back(tx);
}

void Blockchain::mine_pending(const std::string &miner_address) {
  Transaction reward{"", miner_address, MINING_REWARD, ""};
  std::vector<Transaction> current_transactions = pending;
  current_transactions.push_back(reward);

  Block new_block(blocks.size(), current_transactions, blocks.back().hash);
  new_block.mine(difficulty);

  blocks.push_back(new_block);
  pending.clear();
}

bool Blockchain::is_valid() const {
  for (unsigned long i = 1; i < blocks.size(); ++i) {
    const Block *previous = &blocks[i - 1];
    const Block *current = &blocks[i];

    if (current->hash != current->calculate_hash()) {
      std::cout << "Block: " << current->index << ": hash not matching";
      return false;
    }
    if (current->prev_hash != previous->hash) {
      std::cout << "Block: " << previous->index << ": prev_hash not matching";
      return false;
    }
    if (current->hash.substr(0, difficulty) != std::string(difficulty, '0')) {
      std::cout << "Block: " << current->index
                << ": hash is not matching difficulty";
      return false;
    }
    if (current->merkle_root != merkle_root(current->transactions)) {
      std::cout << "Block: " << current->index
                << ": Transactions is changed (merkle root is not matching)";
      return false;
    }
  }
  return true;
}

void Blockchain::print() const {
  for (const Block &a : blocks) {
    std::cout << "Number: " << a.index << "\tNonce: " << a.nonce
              << "\tHash(16): " << a.hash.substr(0, 16)
              << "\tPrevHash: " << a.prev_hash.substr(0, 16) << std::endl;

    for (const Transaction &tx : a.transactions) {
      std::string sender = tx.from.empty() ? "[нагорода]" : tx.from;

      std::cout << "    " << sender << " -> " << tx.to << ": " << tx.amount
                << std::endl;
    }
  }
}
