#include "UserInfoDisplay.hpp"

void            UserInfoDisplay::showCurses()
{
  refresh();
  std::map<std::string, std::string>::iterator it = _map.begin();
  ++it;
  attron(COLOR_PAIR(4));
  attron(A_BOLD);
  mvprintw(6,1,"%s","User information:");
  attroff(COLOR_PAIR(4));
 attroff(A_BOLD);
  mvprintw(7,1,"%s", (*it).second.c_str());
  it = _map.begin();
  mvprintw(8,1,"%s", (*it).second.c_str());
  refresh();
}
