#include "sha256.h"

#include <iomanip>
#include <openssl/evp.h>
#include <sstream>

std::string sha256(const std::string &input) {
  unsigned char digest[EVP_MAX_MD_SIZE];
  unsigned int length = 0;

  EVP_MD_CTX *ctx = EVP_MD_CTX_new();

  EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
  EVP_DigestUpdate(ctx, input.data(), input.size());
  EVP_DigestFinal_ex(ctx, digest, &length);

  EVP_MD_CTX_free(ctx);

  std::ostringstream str;

  for (unsigned int i = 0; i < length; ++i) {
    str << std::hex << std::setfill('0') << std::setw(2) << (int)digest[i];
  }
  return str.str();

  //
  // 1. Оголосіть масив `digest` типу unsigned char на EVP_MAX_MD_SIZE байтів
  // і змінну `length` типу unsigned int, ініціалізовану нулем.
  // 2. Створіть контекст: EVP_MD_CTX_new().
  // 3. EVP_DigestInit_ex(контекст, EVP_sha256(), nullptr)
  // 4. EVP_DigestUpdate(контекст, вказівник на дані, скільки байтів)
  // Дані беруться з input: .data() і .size().
  // 5. EVP_DigestFinal_ex(контекст, digest, &length)
  // Після цього в digest лежать байти, у length — скільки їх.
  // 6. Звільніть контекст: EVP_MD_CTX_free(...). Не пропускайте цей крок.
  // 7. Заведіть std::ostringstream і в циклі від 0 до length
  // відправте в нього кожен байт як два hex-символи:
  // std::hex, std::setw(2), std::setfill('0') і приведення до int.
  // 8. Поверніть .str() від потоку.
}
