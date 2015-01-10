#ifndef		MAGE_H_
#define		MAGE_H_

#include	"Character.hh"

class Mage : virtual public Character {
protected:
  Mage();

public:
  explicit Mage(std::string const& name, int level);
  ~Mage();

  virtual int	CloseAttack();
  virtual void	RestorePower();
protected:  
  void		sayCreation();
  void		sayCloseAttack();
  void		sayRangeAttack();
  void		sayPowerRestore();
};

#endif
