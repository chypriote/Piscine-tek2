#include	"Mage.hh"

//------------------------------------Mage---------------------------------//
Mage::Mage(std::string const &name, int level) : Character(name, level)
{
  this->_name = name;
  this->_level = level;
  this->_pv = 100;
  this->_power = 100;
  _strength = 6;
  _stamina = 6;
  _intelligence = 12;
  _spirit = 11;
  _agility = 7;
  Range = CLOSE;

  //  _weaponName = std::string("hammer");
  _costClose = 10;
  _costRange = 25;
  _dmgClose = 0;
  _dmgRange = 20;
  _pvRestore = 50;
  _powerRestore = 50;
  _statRange = &Mage::_spirit;
  _statClose = &Mage::_null;
  _statPower = &Mage::_intelligence;

  _maxPv = 100;
  _maxPower = 100;

  sayCreation();
}

Mage::~Mage()
{}

//------------------------------Mage: combat---------------------------//
int		Mage::CloseAttack()
{
  if (_power >= _costClose)
    {
      sayCloseAttack();
      _power -= _costClose;
      Range = RANGE;
      return 0;
    }
  sayNoPower();
  return 0;
}

void		Mage::RestorePower()
{
  _power += (_powerRestore + _intelligence);
  if (_power > 100)
    _power = 100;
  sayPowerRestore();
}

//-------------------------------Mage: say-----------------------------//
void		Mage::sayCreation() {
  std::cout << _name << " teleported" << std::endl; }

void		Mage::sayCloseAttack() {
  std::cout << _name << " blinks" << std::endl; }

void		Mage::sayRangeAttack() {
  std::cout << _name << " launches a fire ball" << std::endl; }

void		Mage::sayPowerRestore() {
  std::cout << _name << " takes a mana potion" << std::endl; }
