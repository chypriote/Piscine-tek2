#include	"Paladin.hh"

//------------------------------------Paladin---------------------------------//
Paladin::Paladin(std::string const &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level)
{
  this->_name = name;
  this->_level = level;
  this->_pv = 100;
  this->_power = 100;
  _strength = 9;
  _stamina = 10;
  _intelligence = 10;
  _spirit = 10;
  _agility = 2;
  Range = CLOSE;

  _null = 0;
  _weaponName = std::string("hammer");
  _costClose = 30;
  _costRange = 25;
  _dmgClose = 20;
  _dmgRange = 20;
  _pvRestore = 70;
  _powerRestore = 100;
  _statClose = &Paladin::_strength;
  _statRange = &Paladin::_spirit;
  _statPower = &Paladin::_null;

  _maxPv = 100;
  _maxPower = 100;

  sayCreation();
}

Paladin::~Paladin()
{}

//-------------------------------Paladin: combat-----------------------------//

int		Paladin::CloseAttack()
{
  if (_power >= _costClose)
    {
      _power = _power - _costClose;
      sayCloseAttack();
      return (_dmgClose + 9);
    }
  sayNoPower();
  return 0;
}

int		Paladin::RangeAttack()
{
  if (_power >= _costRange)
    {
      sayRangeAttack();
      _power -= _costRange;
      return (_dmgRange + 10);
    }
  sayNoPower();
  return 0;
    
}

void		Paladin::Heal()
{
  if (_power >= 10)
    {
      _pv += _pvRestore;
      _power -= 10;
      if (_pv >= _maxPv)
	_pv = _maxPv;
      sayPvRestore();
    }
  else
    sayNoPower();
}

int		Paladin::Intercept()
{
  if (_power >= 10)
    {
      Warrior::sayRangeAttack();
      _power -= 10;
      Range = CLOSE;
      return 0;
    }
  sayNoPower();
  return 0;
}

//-------------------------------Paladin: say-----------------------------//
void		Paladin::sayCreation() {
  std::cout << "the light falls on " << _name << std::endl; }

void		Paladin::sayCloseAttack() {
  std::cout << _name << " strikes with his " << _weaponName << std::endl; }

void		Paladin::sayRangeAttack() {
  std::cout << _name << " launches a fire ball" << std::endl; }

void		Paladin::sayPvRestore() {
  std::cout << _name << " casts a little heal spell" << std::endl; }

void		Paladin::sayPowerRestore() {
  std::cout << _name << " eats" << std::endl; }
