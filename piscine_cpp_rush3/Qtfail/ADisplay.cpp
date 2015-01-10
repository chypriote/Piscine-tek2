#include        "ADisplay.hpp"

ADisplay::ADisplay() {
  _push_layout = true;
}

void    ADisplay::show(bool use_Qt) {
  if (use_Qt)
    showQt();
  else
    showCurses();
  _map.clear();
}

void    ADisplay::setLayout(QVBoxLayout *layout)
{
    _layout = layout;
}

void    ADisplay::addToMap(std::string ref, std::string info) {
  _map.insert(std::pair<std::string, std::string>(ref, info));
}
