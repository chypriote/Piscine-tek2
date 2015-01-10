//
// CPUInfoDisplay.cpp for CPU_indoDisplay in /home/mestro_g/arush3/rush3/Display
// 
// Made by mestrot garpard
// Login   <mestro_g@epitech.net>
// 
// Started on  Sun Jan 26 02:36:57 2014 mestrot garpard
// Last update Sun Jan 26 08:56:26 2014 Nicolas Temenides
//

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
