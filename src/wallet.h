#pragma once
#include <string>

struct evp_pkey_st;
typedef evp_pkey_st EVP_PKEY;

class Wallet {
public:
  Wallet();
  ~Wallet();

  Wallet(const Wallet &) = delete;
  Wallet &operator=(const Wallet &) = delete;

  std::string address() const;

  std::string sign(const std::string &message) const;

private:
  EVP_PKEY *key_;
};

bool verify_signature(const std::string &address, const std::string &message,
                      const std::string &signature_hex);
