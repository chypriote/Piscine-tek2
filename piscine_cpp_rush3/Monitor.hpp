#ifndef		MONITOR_H_
#define		MONITOR_H_

#include	<string>
#include	<iostream>
#include	<vector>

#include	"misc.hpp"
#include	"Modules/AModule.hpp"

class	Monitor {
public:
  Monitor(bool);
  ~Monitor();

  void		refresh();
  void		display();
protected:
  bool				_use_Qt;
  std::vector<AModule *>	_modules;
};

#endif
