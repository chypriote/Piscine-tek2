#include	"ADisplay.hpp"

void	ADisplay::show(bool use_Qt) {
  if (use_Qt)
    std::cout << "Displaying with Qt" << std::endl;
  else
    showCurses();
  _map.clear();
}


void	ADisplay::addToMap(std::string ref, std::string info) {
  _map.insert(std::pair<std::string, std::string>(ref, info));
}
