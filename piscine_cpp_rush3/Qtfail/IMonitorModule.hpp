#ifndef		IMONITORMODULE_H_
#define		IMONITORMODULE_H_

#include	<string>
#include	<iostream>

class	IMonitorModule {
public:
  virtual ~IMonitorModule() {}
  
  virtual void	fillMap() = 0;
};

#endif	/*	IMONITORMODULE_H_	*/
