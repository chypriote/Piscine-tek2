#ifndef		IMODULEDISPLAY_H_
#define		IMODULEDISPLAY_H_

#include	<string>
#include	<iostream>
#include	<sstream>

#include	"curses.hpp"
#include	"../misc.hpp"

class	IModuleDisplay {
public:
  virtual ~IModuleDisplay() {}

  virtual void	show(bool) = 0;
  virtual void	showCurses() = 0;
  //  virtual void	showQt() = 0;
};

#endif	/*	IMODULEDISPLAY_H_	*/
