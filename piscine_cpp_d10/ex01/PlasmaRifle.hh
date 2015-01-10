#ifndef		PLASMARIFLE_H_
#define		PLASMARIFLE_H_

#include	"AWeapon.hh"

class PlasmaRifle : virtual public AWeapon {
public:
  PlasmaRifle();
  ~PlasmaRifle();

  virtual void	attack() const;
};

#endif
