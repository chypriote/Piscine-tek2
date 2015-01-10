#include	"Cesar.h"

Cesar::Cesar() {
  reset(); }

Cesar::~Cesar() {}

void	Cesar::encryptChar(char plainchar) {
  if (isalpha(plainchar)) {
    int	i = plainchar > 96 ? 97 : 65;
    plainchar = (plainchar - i + _shift) % 26 + i;
  }
  _shift = (_shift + 1) % 26;
  std::cout << plainchar;
}

void	Cesar::decryptChar(char cipherchar) {
  if (isalpha(cipherchar)) {
    int	i = cipherchar > 96 ? 122 : 90;
    cipherchar = (cipherchar - i - _shift) % 26 + i;
  }
  _shift = (_shift + 1) % 26;
  std::cout << cipherchar;
}

void	Cesar::reset() {
  _shift = 3; }
