#include	"Character.hh"
#include	"RadScorpion.hh"
#include	"PlasmaRifle.hh"
#include	"PowerFist.hh"

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(NULL)
{ }

Character::~Character() { }

//--------------------------------Character: getters-------------------------------//
std::string const	Character::getName() const {
  return _name; }

int		Character::getAp() const {
  return _ap; }

AWeapon*	Character::getWeapon() const {
  return _weapon; }

//--------------------------------Character: functions-------------------------------//
void		Character::recoverAP() {
  _ap += 10;
  if (_ap > 40)
    _ap = 40;
}

void		Character::equip(AWeapon *weapon) {
  _weapon = weapon; }

void		Character::attack(AEnemy *enemy) {
  if (_weapon && enemy && _ap >= _weapon->getAPCost())
    {
      enemy->takeDamage(_weapon->getDamage());
      _ap -= _weapon->getAPCost();
      std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
      _weapon->attack();
      if (enemy->getHP() <= 0)
	delete enemy;
    }
}

//--------------------------------Character: overload-------------------------------//
std::ostream&	operator<<(std::ostream& file, Character const& charac) {
  file << charac.getName() << " has " << charac.getAp() << " AP and ";
  if (charac.getWeapon())
    std::cout << "wields a " << charac.getWeapon()->getName() << std::endl;
  else 
    std::cout <<"is unarmed" << std::endl;
  return file;
}
