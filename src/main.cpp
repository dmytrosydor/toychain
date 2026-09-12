#include "blockchain.h"
#include <iostream>

int main() {
  Blockchain chain;
  chain.add_block("Аліса -> Боб: 10");
  chain.add_block("Боб -> Карл: 5");
  chain.add_block("Карл -> Аліса: 2");
  chain.print();
  std::cout << "Ланцюг валідний? " << (chain.is_valid() ? "так" : "НІ")
            << "\n\n";
  // Атака 1: змінюємо дані в середині ланцюга.
  std::cout << "Підробляємо блок 1...\n";
  chain.blocks[1].data = "Аліса -> Боб: 1000";
  std::cout << "Ланцюг валідний? " << (chain.is_valid() ? "- Так" : " - НІ")
            << "\n\n";
  // Атака 2: перераховуємо hash підробленого блоку, щоб "замести сліди".
  std::cout << "Перераховуємо hash блоку 1...\n";
  chain.blocks[1].hash = chain.blocks[1].calculate_hash();
  std::cout << "Ланцюг валідний? " << (chain.is_valid() ? "так" : " - НІ")
            << "\n";

  std::cout << "Blocks in chain: " << chain.lenght() << std::endl;
  return 0;
}
