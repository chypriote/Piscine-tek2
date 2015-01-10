#ifndef		RAMINFO_H_
#define		RAMINFO_H_

#include	"AModule.hpp"
#include	"../Display/RAMInfoDisplay.hpp"

class	RAMInfo : public AModule {
public:
  RAMInfo();
  virtual ~RAMInfo();

  void		fillMap();
};

#endif
