#ifndef		KOALADOCTORLIST_H_
#define		KOALADOCTORLIST_H_

#include	<string>
#include	<iostream>
#include	"koaladoctor.h"

struct		KoalaDoctorList
{
  KoalaDoctorList(KoalaDoctor *);
  ~KoalaDoctorList();

  KoalaDoctor		*doctor;
  KoalaDoctorList	*next;

  bool			isEnd();
  void			append(KoalaDoctorList *);
  KoalaDoctor		*getFromName(std::string);
  KoalaDoctorList	*remove(KoalaDoctorList *);
  KoalaDoctorList	*removeFromName(std::string);
  void			dump();
};

#endif
