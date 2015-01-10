#ifndef		POWERFIST_H_
#define		POWERFIST_H_

#include	"AWeapon.hh"

class PowerFist : virtual public AWeapon {
public:
  PowerFist();
  ~PowerFist();

  virtual void	attack() const;
};

#endif
