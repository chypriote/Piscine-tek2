#include	"Sorcerer.hh"


Sorcerer::Sorcerer(std::string name, std::string title)
{
  _name = name;
  _title = title;
  sayCreation();
}

Sorcerer::~Sorcerer() {
  sayDestruction(); }

//-------------------------------Sorcerer: getters-------------------------------------//
std::string const&	Sorcerer::getName() const {
  return _name; }

std::string const&	Sorcerer::getTitle() const {
  return _title; }

//--------------------------------Sorcerer: functions---------------------------------//
void		Sorcerer::polymorph(Victim const& victim) const {
  victim.getPolymorphed(); }

//---------------------------------Sorcerer: operators--------------------------------//
std::ostream&	operator<<(std::ostream& file, Sorcerer const& sorcerer) {
  file << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
  return file;
}

//---------------------------------Sorcerer: say--------------------------------//
void	Sorcerer::sayCreation() {
  std::cout << _name << ", " << _title << ", is born !" << std::endl; }

void	Sorcerer::sayDestruction() {
  std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl; }
