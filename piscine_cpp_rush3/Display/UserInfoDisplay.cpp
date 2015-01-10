//
// UserInfoDisplay.cpp for UserInfo.cpp in /home/mestro_g/arush3/rush3/Display
// 
// Made by mestrot garpard
// Login   <mestro_g@epitech.net>
// 
// Started on  Sun Jan 26 02:01:42 2014 mestrot garpard
// Last update Sun Jan 26 03:19:17 2014 Nicolas Temenides
//

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
