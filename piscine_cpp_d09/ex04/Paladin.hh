#ifndef		PALADIN_H_
#define		PALADIN_H_

#include	"Mage.hh"
#include	"Warrior.hh"
#include	"Priest.hh"

class Paladin : virtual public Warrior, virtual public Priest {
protected:
  Paladin();
public:

  explicit Paladin(std::string const& name, int level);
  ~Paladin();

  virtual void	Heal();
  virtual int	Intercept();
  virtual int	RangeAttack();
  virtual int	CloseAttack();
protected:  
  void		sayCreation();
  void		sayCloseAttack();
  void		sayRangeAttack();
  void		sayPvRestore();
  void		sayPowerRestore();
};

#endif
