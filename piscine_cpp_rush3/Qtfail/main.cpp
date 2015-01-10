#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include "mainwindow.h"
#include "curses.hpp"
#include "Monitor.hpp"


int main(int ac, char *av[])
{
  my_init_curs();
  if (ac > 1 && (std::string(av[1]) == std::string("-t"))) {
    Monitor	m(false);
    int		c = 0;
    timeout(0);
    while (true) {
      m.refresh();
      m.display();
      if (c == 27) {
	my_deinit_curs();
	return 0;
      }
      napms(100);
      c = getch();
    }
  }
  else {
    QApplication app(ac, av);
    QWidget fenetre;

    // Création du layout de formulaire et de ses widgets


    // Création du layout principal de la fenêtre (vertical)
    
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    
    Monitor	m(true);
    m.addWindowLayout(layoutPrincipal);
    // //  m.new_show();
    // //layoutPrincipal->addLayout(formLayout); // Ajout du layout de formulaire
    
    fenetre.setLayout(layoutPrincipal);
    fenetre.show();
    // while (true) {
    //   m.show_window(&app);
    //   napms(100);
    // }
    // m.init_app(&app);
    // while (true) {
    //   napms(1000);
    //   m.refresh();
    //   m.display();
    m.refresh();
    m.display();
  return app.exec();
    
  }
  my_deinit_curs();
  return 0;
}
