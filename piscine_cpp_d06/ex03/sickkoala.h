#ifndef		SICKKOALA_H_
#define		SICKKOALA_H_

#include	<string>
#include	<iostream>

struct		SickKoala
{
  SickKoala(std::string);
  ~SickKoala();

  std::string	name;

  void		say(std::string);
  void		poke();
  bool		takeDrug(std::string);
  void		overDrive(std::string);
};

//void		SickKoalaInit(struct SickKoala *);

#endif
