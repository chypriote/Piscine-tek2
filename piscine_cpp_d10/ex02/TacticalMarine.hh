#ifndef		TACTICALMARINE_H_
#define		TACTICALMARINE_H_

#include	<string>
#include	<iostream>

#include	"ISpaceMarine.hh"

class TacticalMarine : public ISpaceMarine {
public:
  TacticalMarine();
  TacticalMarine(TacticalMarine const&);
  virtual ~TacticalMarine();

  virtual ISpaceMarine *clone() const;
  virtual void battleCry() const;
  virtual void rangedAttack() const;
  virtual void meleeAttack() const;
};

#endif
