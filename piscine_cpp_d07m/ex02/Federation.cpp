#include	"Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  _length = length;
  _width = width;
  _name = name;
  _maxWarp = maxWarp;
  _home = EARTH;
  _location = EARTH;

  std::cout << "The ship USS " + name + " has been finished. It is " << length << " m in length and " << width << " m in width." << std::endl;
  std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void		Federation::Starfleet::Ship::say(std::string str) {
  std::cout << "USS " + this->getName() + ": " + str << std::endl; }

std::string	Federation::Starfleet::Ship::getName() {
  return this->_name; }

int		Federation::Starfleet::Ship::getLength(){
  return this->_length; }

int		Federation::Starfleet::Ship::getWidth() {
  return this->_width; }

short		Federation::Starfleet::Ship::getWarp() {
  return this->_maxWarp; }

WarpSystem::Core	*Federation::Starfleet::Ship::getCore() {
  return this->_core;
}

void		Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
  this->_core = core;
  this->say("The core is set.");
}

void		Federation::Starfleet::Ship::checkCore()
{
  if (_core)
    {
      if (_core->getStability())
	this->say("The core is stable at the time.");
      else
	this->say("The core is unstable at the time.");
    }
}

bool		Federation::Starfleet::Ship::isStable()
{
  if (getCore())
    return getCore()->isStable();
  return false;
}

void		Federation::Starfleet::Ship::promote(Captain *captain) {
  _captain = captain;
  std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool		Federation::Starfleet::Ship::move(int warp, Destination d)
{
  if (warp <= _maxWarp && d != _location && isStable())
    {
      _location = d;
      return true;
    }
  return false;
}

bool		Federation::Starfleet::Ship::move(int warp) {
  return move(warp, _home); }

bool		Federation::Starfleet::Ship::move(Destination d) {
  return move(_maxWarp, d); }

bool		Federation::Starfleet::Ship::move() {
  return move(_maxWarp, _home); }

//-------------------------------------Ship---------------------------------//

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  _home = VULCAN;
  _location = VULCAN;

  std::cout << "The independant ship " + name + " just finished its construction. It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void		Federation::Ship::say(std::string str) {
  std::cout << this->getName() + ": " + str << std::endl; }

std::string	Federation::Ship::getName() {
  return this->_name; }

int		Federation::Ship::getLength(){
  return this->_length; }

int		Federation::Ship::getWidth() {
  return this->_width; }

WarpSystem::Core	*Federation::Ship::getCore() {
  return this->_core;
}

void		Federation::Ship::setupCore(WarpSystem::Core *core)
{
  this->_core = core;
  this->say("The core is set.");
}

void		Federation::Ship::checkCore()
{
  if (_core)
    {
      if (_core->getStability())
	this->say("The core is stable at the time.");
      else
	this->say("The core is unstable at the time.");
    }
}

bool		Federation::Ship::isStable()
{
  if (getCore())
    return getCore()->isStable();
  return false;
}

bool		Federation::Ship::move(int warp, Destination d)
{
  if (warp <= 1 && d != _location && isStable())
    {
      _location = d;
      return true;
    }
  return false;
}

bool		Federation::Ship::move(int warp) {
  return move(warp, _home); }

bool		Federation::Ship::move(Destination d) {
  return move(_maxWarp, d); }

bool		Federation::Ship::move() {
  return move(_maxWarp, _home); }


//-----------------------------------------Captain--------------------------------------//

Federation::Starfleet::Captain::Captain(std::string name) {
  _name = name; }

Federation::Starfleet::Captain::~Captain()
{ }

void	Federation::Starfleet::Captain::setAge(int age) {
  _age = age; }

int	Federation::Starfleet::Captain::getAge() {
  return _age; }

std::string	Federation::Starfleet::Captain::getName() {
  return _name; }


//-----------------------------------------Ensign--------------------------------------//

Federation::Starfleet::Ensign::Ensign(std::string name) {
  if (!name.empty())
    {
      _name = name;
      std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
    }
}

Federation::Starfleet::Ensign::~Ensign()
{ }

std::string	Federation::Starfleet::Ensign::getName() {
  return _name; }
