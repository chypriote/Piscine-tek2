#ifndef		KOALANURSE_H_
#define		KOALANURSE_H_

#include	<string>
#include	<iostream>

struct		KoalaNurse
{
  KoalaNurse(int);
  ~KoalaNurse();

  int		id;
  bool		work;
  
  void		say(std::string);
  void		giveDrug(std::string, SickKoala *);
  std::string	readReport(std::string);
  void		timeCheck();
};

#endif
