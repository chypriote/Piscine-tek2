#include "CPUInfoDisplay.hpp"

static void             _display_diagram(std::map<std::string, std::string>::iterator it, int line)
{
  int                   nb;
  int                   i = 0;
  int                   tmp;

  nb = my_stoi(it->second);
  tmp = nb;

  while (i < nb/2)
    {
      if (i >= 30)
        attron(COLOR_PAIR(1));
      if (i >= 20 && i < 30)
        attron(COLOR_PAIR(5));
      if (i >= 0 && i < 20)
        attron(COLOR_PAIR(2));
      mvprintw(12 + line, i + 2,"|");
      attron(COLOR_PAIR(4));
      mvprintw(12 + line, i + 4, "%d%%",tmp / 2);
      attroff(COLOR_PAIR(4));
      attroff(COLOR_PAIR(1));
      attroff(COLOR_PAIR(2));
      attroff(COLOR_PAIR(3));
      ++i;
    }
}

void	CPUInfoDisplay::showCurses()
{
  int   line = 0;

  refresh();
  std::map<std::string, std::string>::iterator itt = _map.end();
  --itt;
  mvprintw(11, 1, (*itt).second.c_str());
  std::map<std::string, std::string>::iterator it = _map.begin();;
  // it--;                                                                                               
  attron(A_BOLD);
  attron(COLOR_PAIR(4));
  mvprintw(10,1,"%s","CPU information:");
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
  while (it != _map.end())
    {
      _display_diagram(it, line);
      ++line;
      ++it;
    }
  // mvprintw(11,1,"%s",(*it).second.c_str());                                                           
  refresh();

}
