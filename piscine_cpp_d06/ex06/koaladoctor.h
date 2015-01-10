#ifndef		KOALADOCTOR_H_
#define		KOALADOCTOR_H_

#include	<string>
#include	<iostream>
#include	"sickkoala.h"

struct		KoalaDoctor
{
  KoalaDoctor(std::string);
  ~KoalaDoctor();

  std::string	name;
  bool		work;
  
  void		say(std::string);
  void		diagnose(SickKoala *);
  void		timeCheck();
  std::string	getName();
};

//void		KoalaDoctorInit(struct KoalaDoctor *);

#endif
