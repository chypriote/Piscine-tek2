#ifndef		AMODULE_H_
#define		AMODULE_H_

#include	"IMonitorModule.hpp"
#include	"../Display/ADisplay.hpp"

class	AModule : public IMonitorModule {
public:
  AModule() {}
  virtual ~AModule() {}

  virtual void	fillMap() = 0;

public:
  bool		_refresh;
  std::string	_filename;
  ADisplay*	_display;
};

#endif		/*	!AMODULE_H_	*/
