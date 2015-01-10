#include	"Victim.hh"


Victim::Victim(std::string name)
{
  _name = name;
  sayCreation();
}

Victim::~Victim() {
  sayDestruction(); }

//--------------------------------Victim: getters--------------------------------//
std::string const&	Victim::getName() const {
  return _name; }

//--------------------------------Victim: functions--------------------------------//
void		Victim::getPolymorphed() const {
  sayPolymorph(); }

//---------------------------------Victim: operators--------------------------------//
std::ostream&	operator<<(std::ostream& file, Victim const& victim) {
  file << "I'm " << victim.getName() << " and i like otters !" << std::endl;
  return file;
}

//---------------------------------Victim: say--------------------------------//
void	Victim::sayCreation() {
  std::cout << "Some random victim called " <<  _name << " just popped !" << std::endl; }

void	Victim::sayDestruction() {
  std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl; }

void	Victim::sayPolymorph() const {
  std::cout << _name << " has been turned into a cute little sheep !" << std::endl; }
