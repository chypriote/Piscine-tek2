#include	"misc.hpp"

std::string	my_itos(int n) {
  std::ostringstream	a;

  a << n;
  return a.str();
}

int		my_stoi(std::string str) {
  std::istringstream		a(str);
  int		b;
  a >> b;
  return b;
}
