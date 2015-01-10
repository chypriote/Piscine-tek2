#include	"Peon.hh"

Peon::Peon(std::string const &name) : Victim(name)
{
  sayCreation();
}

Peon::~Peon() {
  sayDestruction(); }

//--------------------------------Peon: functions----------------------------------//
void		Peon::getPolymorphed() const {
  sayPolymorph(); }

//--------------------------------Peon: say--------------------------------------//
void		Peon::sayCreation() {
  std::cout << "Zog zog." << std::endl; }

void		Peon::sayDestruction() {
  std::cout << "Bleuark..." << std::endl; }

void		Peon::sayPolymorph() const {
  std::cout << _name << " has been turned into a pink pony !" << std::endl; }
