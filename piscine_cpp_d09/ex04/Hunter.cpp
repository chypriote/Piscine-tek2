#include	"Hunter.hh"

//------------------------------------Hunter---------------------------------//
Hunter::Hunter(std::string const &name, int level) : Character(name, level)
{
  this->_name = name;
  this->_level = level;
  this->_pv = 100;
  this->_power = 100;
  _strength = 9;
  _stamina = 9;
  _intelligence = 5;
  _spirit = 6;
  _agility = 24;
  Range = CLOSE;

  _weaponName = std::string("sword");
  _costClose = 30;
  _costRange = 25;
  _dmgClose = 20;
  _dmgRange = 20;
  _pvRestore = 50;
  _powerRestore = 100;
  _statClose = &Hunter::_strength;
  _statRange = &Hunter::_agility;
  _statPower = &Hunter::_null;

  _maxPv = 100;
  _maxPower = 100;

  sayCreation();
}

Hunter::~Hunter()
{}

//-------------------------------Hunter: combat-----------------------------//
int		Hunter::RangeAttack()
{
  if (_power >= _costRange)
    {
      sayRangeAttack();
      _power -= _costRange;
      Range = CLOSE;
      return (20 + _agility);
    }
  sayNoPower();
  return 0;
}

//-------------------------------Hunter: say-----------------------------//
void		Hunter::sayCreation() {
  std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
  std::cout << _name << " is born from a tree" << std::endl; }

void		Hunter::sayCloseAttack() {
  std::cout << _name << " strikes with his " << _weaponName << std::endl; }

void		Hunter::sayRangeAttack() {
  std::cout << _name << " uses his bow" << std::endl; }

void		Hunter::sayPowerRestore() {
  std::cout << _name << " meditates" << std::endl; } 
