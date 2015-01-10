#ifndef		HOPITAL_H_
#define		HOPITAL_H_

#include <string>
#include <iostream>
#include <sstream>
#include "sickkoala.h"
#include "koalanurse.h"
#include "koaladoctor.h"
#include "sickkoalalist.h"
#include "koalanurselist.h"
#include "koaladoctorlist.h"

struct	 Hospital
{
  Hospital();
  ~Hospital();
  SickKoalaList		*koalas;
  KoalaNurseList	*nurses;
  KoalaDoctorList	*doctors;


  void			action(std::string action);
  void			addSick(SickKoalaList *koala);
  void			addNurse(KoalaNurseList *nurse);
  void			addDoctor(KoalaDoctorList *doctor);
  void			run();

};

#endif
