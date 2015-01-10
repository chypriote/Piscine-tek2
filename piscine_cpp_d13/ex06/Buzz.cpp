#include	"Buzz.h"

Buzz::Buzz(std::string const& name): Toy(BUZZ, name, "./buzz.txt") { }

Buzz::Buzz(std::string const& name, std::string const& filename):
  Toy(BUZZ, name, filename)
{ }


bool	Buzz::speak(std::string const& str) {
  std::cout << "BUZZ: " << _name << " \"" << str << "\"" << std::endl; 
  return true;
}

bool	Buzz::speak_es(std::string const& str) {
  std::cout << "BUZZ: " << _name << " senorita \"" << str << "\" senorita" << std::endl; 
  return true;
}
