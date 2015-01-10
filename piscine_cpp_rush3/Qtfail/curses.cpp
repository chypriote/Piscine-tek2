#include	"curses.hpp"

void    my_init_curs()
{
  initscr();
  noecho();
  raw();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  curs_set(0);
}

void    my_deinit_curs()
{
  int   c;
  while ((c=getch())!= 27);
  endwin();
}

