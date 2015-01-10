#include	"OneTime.h"

OneTime::OneTime(std::string const& key): _key(key), _id(0) {}

OneTime::~OneTime() {}

void	OneTime::encryptChar(char plainchar) {
  if (isalpha(plainchar)) {
    int i = plainchar > 96 ? 97 : 65;
    int	n = _key[_id] > 96 ? 97 : 65;
    plainchar = ((plainchar - i + (_key[_id] - n)) % 26) + i;
  }
  std::cout << plainchar;
  _id = (_id + 1) % _key.size();
}

void	OneTime::decryptChar(char cipherchar) {
  if (isalpha(cipherchar)) {
    int i = cipherchar > 96 ? 122 : 90;
    int	n = _key[_id] > 96 ? 97 : 65;
    cipherchar = ((cipherchar - i - (_key[_id] - n)) % 26) + i;
  }
  std::cout << cipherchar;
  _id = (_id + 1) % _key.size();
}

void	OneTime::reset() {
  _id = 0; }
