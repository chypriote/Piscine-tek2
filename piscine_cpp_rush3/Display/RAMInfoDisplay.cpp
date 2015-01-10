//
// RAMInfoDisplay.cpp for Raminfodisplay in /home/mestro_g/arush3/rush3/Display
// 
// Made by mestrot garpard
// Login   <mestro_g@epitech.net>
// 
// Started on  Sun Jan 26 02:08:23 2014 mestrot garpard
// Last update Sun Jan 26 03:20:17 2014 Nicolas Temenides
//

#include "RAMInfoDisplay.hpp"

void            RAMInfoDisplay::showCurses()
{
  int		i = 0;
  int		nb;

  refresh();
  std::map<std::string, std::string>::iterator it = _map.begin();
  ++it;
  ++it;
  attron(COLOR_PAIR(4));
  mvprintw(9, 53, "%s%% of the memory used.",(*it).second.c_str());
  attroff(COLOR_PAIR(4));
  nb = my_stoi(it->second);
  while (i < nb/2)
    {
      if (i >= 30)
        attron(COLOR_PAIR(1));
      if (i >= 20 && i < 30)
        attron(COLOR_PAIR(2));
      if (i >= 0 && i < 20)
        attron(COLOR_PAIR(3));
      mvprintw(9, i + 2,"|");
      attroff(COLOR_PAIR(1));
      attroff(COLOR_PAIR(2));
      attroff(COLOR_PAIR(3));
      ++i;
    }
  refresh();
}
