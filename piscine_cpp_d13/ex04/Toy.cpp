#include	"Toy.h"

Toy::Toy(): _type(BASIC_TOY), _name("toy") {}

Toy::Toy(enum ToyType type, std::string const& name, std::string const& ascii)
  : _type(type), _name(name) {
  _picture.getPictureFromFile(ascii);
}

Toy::Toy(Toy const& toy): _type(toy._type), _name(toy._name), _picture(toy._picture) {}

Toy::~Toy() {}

Toy&	Toy::operator =(Toy const& toy) {
  _type = toy._type;
  _name = toy._name;
  _picture = toy._picture;
  return *this;
}

//---------------------Getters
int		Toy::getType() const {
  return _type; }

std::string const&	Toy::getName() const {
  return  _name; }

std::string const&	Toy::getAscii() const {
  return _picture.data; }

//--------------------Setters
void		Toy::setName(std::string const& name) {
  _name = name; }

bool		Toy::setAscii(std::string const& ascii) {
  return _picture.getPictureFromFile(ascii); }

//--------------------Functions
void		Toy::speak(std::string const& str) {
  std::cout << _name << " \"" << str << "\"" << std::endl; }

Toy&		Toy::operator<<(std::string const& ascii) {
  _picture.data = ascii;
  return *this;
}

std::ostream&	 operator<<(std::ostream& os, Toy const& toy) {
  return os << toy.getName() << std::endl << toy.getAscii() << std::endl; }
