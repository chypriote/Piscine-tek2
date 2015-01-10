#include	"AWeapon.hh"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage)
{ }

AWeapon::~AWeapon() { }

//---------------------------AWeapon: getters------------------------------------//
std::string const&	AWeapon::getName() const {
  return _name; }

int		AWeapon::getAPCost() const {
  return _apcost; }

int		AWeapon::getDamage() const {
  return _damage; }

