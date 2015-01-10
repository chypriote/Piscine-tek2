#ifndef		WARRIOR_H_
#define		WARRIOR_H_

#include	"Character.hh"

class Warrior : virtual public Character {
protected:
  Warrior();
public:

  explicit Warrior(std::string const& name, int level);
  ~Warrior();

  virtual int	RangeAttack();
protected:  
  void		sayCreation();
  void		sayCloseAttack();
  void		sayRangeAttack();
};

#endif
