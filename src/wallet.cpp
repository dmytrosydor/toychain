#include "wallet.h"

#include <openssl/core_names.h>
#include <openssl/evp.h>
#include <openssl/param_build.h>

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <vector>

static std::string to_hex(const std::vector<unsigned char> &bytes) {

  std::ostringstream str;

  for (unsigned int i = 0; i < bytes.size(); ++i) {
    str << std::hex << std::setfill('0') << std::setw(2) << (int)bytes[i];
  }
  return str.str();
}

static std::vector<unsigned char> from_hex(const std::string &hex) {

  std::vector<unsigned char> bytes;
  for (unsigned int i = 0; i < hex.size(); i += 2) {
    int byte_val = std::stoi(hex.substr(i, 2), nullptr, 16);
    bytes.push_back(static_cast<unsigned char>(byte_val));
  }
}
