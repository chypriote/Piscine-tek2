#include	"Priest.hh"

//------------------------------------Priest---------------------------------//
Priest::Priest(std::string const &name, int level) : Character(name, level), Mage(name, level)
{
  this->_name = name;
  this->_level = level;
  this->_pv = 100;
  this->_power = 100;
  _strength = 4;
  _stamina = 4;
  _intelligence = 42;
  _spirit = 21;
  _agility = 2;
  Range = CLOSE;

  //  _weaponName = std::string("hammer");
  _costClose = 10;
  _costRange = 25;
  _dmgClose = 10;
  _dmgRange = 20;
  _pvRestore = 70;
  _powerRestore = 100;
  _statClose = &Priest::_spirit;
  _statRange = &Priest::_spirit;
  _statPower = &Priest::_null;

  _maxPv = 100;
  _maxPower = 100;

  sayCreation();
}

Priest::~Priest()
{}
//------------------------------Priest: combat--------------------------//

int		Priest::CloseAttack()
{
  if (_power >= 10)
    {
      sayCloseAttack();
      _power -= _costClose;
      return (10 + _spirit);
    }
  sayNoPower();
  return 0;
}

void		Priest::Heal()
{
  if (_power >= 10)
    {
      _power -= 10;
      sayPvRestore();
      _pv += 70;
      if (_pv > 100)
	_pv = 100;
    }
  else
    sayNoPower();
}

//-------------------------------Priest: say-----------------------------//
void		Priest::sayCreation() {
  std::cout << _name << " enters in the order" << std::endl; }

void		Priest::sayCloseAttack() {
  std::cout << _name << " uses a spirit explosion" << std::endl; }

void		Priest::sayRangeAttack() {
  std::cout << _name << " launches a fire ball" << std::endl; }

void		Priest::sayPvRestore() {
  std::cout << _name << " casts a little heal spell" << std::endl; }
