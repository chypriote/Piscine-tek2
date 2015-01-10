#ifndef		ASSAULTTERMINATOR_H_
#define		ASSAULTTERMINATOR_H_

#include	<string>
#include	<iostream>

#include	"ISpaceMarine.hh"

class AssaultTerminator : public ISpaceMarine {
public:
  AssaultTerminator();
  AssaultTerminator(AssaultTerminator const&);
  virtual ~AssaultTerminator();

  virtual ISpaceMarine *clone() const;
  virtual void battleCry() const;
  virtual void rangedAttack() const;
  virtual void meleeAttack() const;
};

#endif
