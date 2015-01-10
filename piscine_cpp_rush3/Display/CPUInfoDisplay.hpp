#ifndef		CPUINFO_DISPLAY_H_
#define		CPUINFO_DISPLAY_H_

#include	"ADisplay.hpp"

class	CPUInfoDisplay : public ADisplay {
public:
  CPUInfoDisplay() {}
  ~CPUInfoDisplay() {}

  void		showCurses();
};

#endif	/*	CPUINFO_DISPLAY_H_	*/
