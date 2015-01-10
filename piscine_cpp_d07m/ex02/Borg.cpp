#include	"Borg.hh"
#include	"Warpsystem.hh"

Borg::Ship::Ship()
{
  _side = 300;
  _maxWarp = 9;
  _home = UNICOMPLEX;
  _location = UNICOMPLEX;

  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{ }

void	Borg::Ship::say(std::string str) {
  std::cout << str << std::endl; }

int	Borg::Ship::getSide() {
  return _side; }

short	Borg::Ship::getWarp() {
  return _maxWarp; }

WarpSystem::Core	*Borg::Ship::getCore() {
  return _core; }

bool	Borg::Ship::isStable() {
  if (getCore())
    return getCore()->isStable();
  return false;
}

void	Borg::Ship::setupCore(WarpSystem::Core *core) {
  _core = core; }

void	Borg::Ship::checkCore() {
  if (_core)
    {
      if (_core->getStability())
	say("Everything is in order.");
      else
	say("Critical failure imminent.");
    }
}

bool            Borg::Ship::move(int warp, Destination d)
{
  if (warp <= _maxWarp && d != _location && isStable())
    {
      _location = d;
      return true;
    }
  return false;
}

bool            Borg::Ship::move(int warp) {
  return move(warp, _home); }

bool            Borg::Ship::move(Destination d) {
  return move(_maxWarp, d); }

bool            Borg::Ship::move() {
  return move(_maxWarp, _home); }
