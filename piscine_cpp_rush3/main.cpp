#include	"Monitor.hpp"
#include	"Modules/DateHour.hpp"
#include	"Modules/OSKernel.hpp"
#include	"Modules/UserInfo.hpp"
#include	"Modules/RAMInfo.hpp"
#include	"Modules/CPUInfo.hpp"
#include	"Modules/Network.hpp"
#include	"Display/curses.hpp"

int	main() {
  int		c = 0;
    
  //  if (ac > 1 && (std::string(av[1]) == std::string("-t"))) {
    Monitor	m(false);

    my_init_curs();
    timeout(0);
    while (true) {
      m.refresh();
      m.display();
      if (c == 27) {
	my_deinit_curs();
	return 0;
      }
      napms(1000);
      c = getch();
    }
    my_deinit_curs();
    /*  }
  else {
    //ajouter fonction Qt de folie
    Monitor	m(true);
    while (true) {
      m.refresh();
      m.display();
      if (c == 27) {
	return 0;
      }
      napms(1000);
      c = getch();
      }
  }*/
  return 0;
}
