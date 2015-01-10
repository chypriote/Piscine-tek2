#include	"Woody.h"

Woody::Woody(std::string const& name): Toy(WOODY, name, "./woody.txt") { }

Woody::Woody(std::string const& name, std::string const& filename):
  Toy(WOODY, name, filename)
{ }
