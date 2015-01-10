#ifndef		KOALABOT_H_
#define		KOALABOT_H_

#include	<string>
#include	<iostream>
#include	"Parts.h"

class KoalaBot {
 private:
  std::string	serial;
  Arms		arms;
  Legs		legs;
  Head		head;
  
 public:
  KoalaBot(std::string serial = "Bob-01");
  ~KoalaBot();

  void		setParts(Arms&);
  void		setParts(Legs&);
  void		setParts(Head&);
  void		swapParts(Arms&);
  void		swapParts(Head&);
  void		swapParts(Legs&);

  void		informations() const;
  bool		status() const;
};

#endif
