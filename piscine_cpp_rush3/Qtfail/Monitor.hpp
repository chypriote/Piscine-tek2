#ifndef		MONITOR_H_
#define		MONITOR_H_

#include	<string>
#include	<iostream>
#include	<vector>
#include <QObject>
#include	"AModule.hpp"
#include	"curses.hpp"
#include    "misc.hpp"

class	Monitor: public QWidget {
public:
  Monitor(bool);
  ~Monitor();

  void	refresh();
  void  display();
  void addWindowLayout(QVBoxLayout *layout);
public slots:
  void	show_window();
protected:
  bool				_use_Qt;
  std::vector<AModule *>	_modules;
};

#endif
