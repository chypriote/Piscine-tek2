#ifndef		KOALANURSELIST_H_
#define		KOALANURSELIST_H_

#include	<string>
#include	<iostream>
#include	"koalanurse.h"
#include	"sickkoala.h"

struct		KoalaNurseList
{
  KoalaNurseList(KoalaNurse *);
  ~KoalaNurseList();

  KoalaNurse		*nurse;
  KoalaNurseList	*next;

  bool			isEnd();
  void			append(KoalaNurseList *);
  KoalaNurse		*getFromID(int);
  KoalaNurseList	*remove(KoalaNurseList *);
  KoalaNurseList	*removeFromID(int);
  void			dump();
};

#endif
