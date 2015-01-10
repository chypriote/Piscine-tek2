#include	"Warrior.hh"

//------------------------------------Warrior---------------------------------//
Warrior::Warrior(std::string const &name, int level) : Character(name, level)
{
  this->_name = name;
  this->_level = level;
  this->_pv = 100;
  this->_power = 100;
  _strength = 12;
  _stamina = 12;
  _intelligence = 6;
  _spirit = 5;
  _agility = 7;
  Range = CLOSE;

  _weaponName = std::string("hammer");
  _costClose = 30;
  _costRange = 10;
  _dmgClose = 20;
  _dmgRange = 0;
  _pvRestore = 50;
  _powerRestore = 100;
  _statClose = &Warrior::_strength;
  _statRange = &Warrior::_null;
  _statPower = &Warrior::_null;

  _maxPv = 100;
  _maxPower = 100;

  sayCreation();
}

Warrior::~Warrior()
{}

//-------------------------------Warrior: combat-----------------------------//
int		Warrior::RangeAttack()
{
  if (_power >= _costRange)
    {
      sayRangeAttack();
      _power -= _costRange;
      Range = CLOSE;
      return 0;
    }
  sayNoPower();
  return 0;
}

//-------------------------------Warrior: say-----------------------------//
void		Warrior::sayCreation() {
  std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl; }

void		Warrior::sayCloseAttack() {
  std::cout << _name << " strikes with his " << _weaponName << std::endl; }

void		Warrior::sayRangeAttack() {
  std::cout << _name << " intercepts" << std::endl; }
