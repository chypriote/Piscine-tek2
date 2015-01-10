#ifndef		OSKERNEL_DISPLAY_H_
#define		OSKERNEL_DISPLAY_H_

#include	"ADisplay.hpp"

class	OSKernelDisplay : public ADisplay {
public:
  OSKernelDisplay() {}
  ~OSKernelDisplay() {}

  void		showCurses();
};

#endif	/*	OSKERNEL_DISPLAY_H_	*/
