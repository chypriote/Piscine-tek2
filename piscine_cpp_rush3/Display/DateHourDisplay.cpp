#include "DateHourDisplay.hpp"

void            init_design()
{
  attron(A_BOLD);
  mvprintw(9, 1,"[");
  mvprintw(9, 51,"]");
  mvprintw(12, 1,"[");
  mvprintw(12, 51,"]");
  mvprintw(13, 1,"[");
  mvprintw(13, 51,"]");
  mvprintw(14, 1,"[");
  mvprintw(14, 51,"]");
  mvprintw(15, 1,"[");
  mvprintw(15, 51,"]");
  attron(COLOR_PAIR(4));
  mvprintw(12, 53, "cpu 1");
  mvprintw(13, 53, "cpu 2");
  mvprintw(14, 53, "cpu 3");
  mvprintw(15, 53, "cpu 4");
  mvprintw(18, 1,"Download: ");
  mvprintw(19, 1,"Upload: ");
  mvprintw(18, 19, "kb/s");
  mvprintw(19, 19, "kb/s");
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
}


void	DateHourDisplay::showCurses()
{
  erase();
  refresh();
  std::map<std::string, std::string>::iterator it = _map.begin();
  attron(A_BOLD);
  attron(COLOR_PAIR(4));
  mvprintw(1,1,"%s","Date and time:");
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
  mvprintw(2,1,"%s", (*it).second.c_str());
  ++it;
  mvprintw(2,12,"%s", (*it).second.c_str());
  init_design();
  refresh();
}
