#include "sha256.h"
#include <iostream>

int main() {
  std::cout << "hello -> " << sha256("hello") << "\n";
  std::cout << "hello! -> " << sha256("hello") << "\n";
  std::cout << "Empty -> " << sha256("") << "\n";
}
