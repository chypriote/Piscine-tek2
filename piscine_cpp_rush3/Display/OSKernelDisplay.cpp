#include "OSKernelDisplay.hpp"

void		OSKernelDisplay::showCurses()
{
  refresh();
  std::map<std::string, std::string>::iterator it = _map.begin();
  ++it;
  attron(A_BOLD);
  attron(COLOR_PAIR(4));
  mvprintw(3,1,"%s","OS and Kernel used:");
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
  mvprintw(4,1,"%s", (*it).second.c_str());
  it = _map.begin();
  mvprintw(5,1,"%s", (*it).second.c_str());
  refresh();
}
