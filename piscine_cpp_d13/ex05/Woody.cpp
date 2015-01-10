#include	"Woody.h"

Woody::Woody(std::string const& name): Toy(WOODY, name, "./woody.txt") { }

Woody::Woody(std::string const& name, std::string const& filename):
  Toy(WOODY, name, filename)
{ }

bool		Woody::speak(std::string const& str) {
  std::cout << "WOODY: " << _name << " \"" << str << "\"" << std::endl;
  return true;
}
