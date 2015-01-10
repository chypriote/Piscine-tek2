#include	"Character.hh"

//-----------------------------------Character---------------------------//
Character::Character(std::string name, int level) : _name(name), _level(level), _pv(100), _power(100) {
  _strength = 5;
  _stamina = 5;
  _intelligence = 5;
  _spirit = 5;
  _agility = 5;
  Range = CLOSE;
  _null = 0;

  _costClose = 10;
  _costRange = 10;
  _dmgClose = 10;
  _dmgRange = 5;
  _pvRestore = 50;
  _powerRestore = 100;
  _statClose = &Character::_strength;
  _statRange = &Character::_strength;
  _statPower = &Character::_null;

  _maxPv = 100;
  _maxPower = 100;

  sayCreation();
}

Character::~Character()
{ }


//-----------------------------------Character: getters---------------------//

const std::string	&Character::getName() const {
  return _name; }

int			Character::getLvl() const {
  return _level; }

int			Character::getPv() const {
  return _pv; }

int			Character::getPower() const {
  return _power; }

int			Character::getStrength() const {
  return _strength; }

int			Character::getStamina() const {
  return _stamina; }

int			Character::getIntelligence() const {
  return _intelligence; }

int			Character::getSpirit() const {
  return _spirit; }

int			Character::getAgility() const {
  return _agility; }


//----------------------------------Character: combat----------------------//
int		Character::CloseAttack()
{
  if (_power >= _costClose)
    {
      _power = _power - _costClose;
      sayCloseAttack();
      return (_dmgClose + this->*_statClose);
    }
  sayNoPower();
  return 0;
}

int		Character::RangeAttack()
{
  if (_power >= _costRange)
    {
      sayRangeAttack();
      _power -= _costRange;
      return (_dmgRange + this->*_statRange);
    }
  sayNoPower();
  return 0;
}

void		Character::Heal()
{
  _pv += _pvRestore;
  if (_pv >= _maxPv)
    _pv = _maxPv;
  sayPvRestore();
}

void		Character::RestorePower()
{
  _power = _maxPower;
  sayPowerRestore();
}

void		Character::TakeDamage(int damage)
{
  _pv -= damage;
  if (_pv <= 0)
    {
      _pv = 0;
      sayOutCombat();
    }
  else
    sayTakeDamage(damage);
}

//--------------------------------Character: say-----------------------------//
void		Character::sayCreation() {
  std::cout << _name << " Created" << std::endl; }

void		Character::sayNoPower() {
  std::cout << _name << " out of power" << std::endl; }

void		Character::sayOutCombat() {
  std::cout << _name << " out of combat" << std::endl; }

void		Character::sayCloseAttack() {
  std::cout << _name << " strikes with a wood stick" << std::endl; }

void		Character::sayRangeAttack() {
  std::cout << _name << " launches a stone" << std::endl; }

void		Character::sayPvRestore() {
  std::cout << _name << " takes a potion" << std::endl; }

void		Character::sayPowerRestore() {
  std::cout << _name << " eats" << std::endl; }

void		Character::sayTakeDamage(int damage) {
  std::cout << _name << " takes " << damage << " damage" << std::endl; }
