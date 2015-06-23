#include "NetworkDisplay.hpp"

void	NetworkDisplay::showCurses()
{
  refresh();
  std::map<std::string, std::string>::iterator it = _map.begin();
  attron(A_BOLD);
  attron(COLOR_PAIR(4));
  mvprintw(17, 1, "Network:");
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
  mvprintw(18, 12, "%s", (*it).second.substr(0, std::string::npos - 3).c_str());
  it++;
  mvprintw(19, 12, "%s", (*it).second.substr(0, std::string::npos - 3).c_str());
  refresh();

}
