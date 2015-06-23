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
