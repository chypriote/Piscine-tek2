#ifndef		RAMINFO_DISPLAY_H_
#define		RAMINFO_DISPLAY_H_

#include	"ADisplay.hpp"

class	RAMInfoDisplay : public ADisplay {
public:
  RAMInfoDisplay() {}
  ~RAMInfoDisplay() {}

  void		showCurses();
};

#endif	/*	RAMINFO_DISPLAY_H_	*/
