#ifndef		IMONITORMODULE_H_
#define		IMONITORMODULE_H_

#include	<string>
#include	<iostream>
#include	<fstream>
#include	<map>

#include	"../misc.hpp"

class	IMonitorModule {
public:
  virtual ~IMonitorModule() {}
  
  virtual void	fillMap() = 0;
};

#endif	/*	IMONITORMODULE_H_	*/
