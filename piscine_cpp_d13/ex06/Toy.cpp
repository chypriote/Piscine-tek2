#include "Toy.h"

Toy::Toy(): _type(BASIC_TOY), _name("toy") { }

Toy::Toy(enum ToyType type, std::string const& name, std::string const& ascii):
_type(type), _name(name), _picture(ascii)
{}

Toy::Toy(Toy const& toy): _type(toy._type), _name(toy._name), _picture(toy._picture)
{ }

Toy::~Toy() { }

//-------------------Getters
int			Toy::getType() const {
  return _type; }

std::string const&	Toy::getName() const {
  return _name; }

std::string const&	Toy::getAscii() const {
  return _picture.data; }

//-------------------Setters
void			Toy::setName(std::string const& name) {
  this->_name = name; }

bool			Toy::setAscii(std::string const& ascii) {
  if (!_picture.getPictureFromFile(ascii)) {
    _error.setType(Error::PICTURE);
    return false;
  }
  return true;
}


Toy::Error const&	Toy::getLastError() const {
  return _error;
}

//-----------------Functions
bool			Toy::speak(std::string const& str) {
  std::cout << _name << " \"" << str << "\"" << std::endl;
  return true;
}

bool			Toy::speak_es(std::string const& str) {
  (void) str;
  _error.setType(Error::SPEAK);
  return false;
}

Toy&			Toy::operator =(Toy const& toy) {
  _type = toy._type;
  _name = toy._name;
  _picture = toy._picture;
  return *this;
}

Toy&			Toy::operator<<(std::string const &ascii) {
  _picture.data = ascii;
  return *this;
}

//----------------ERRORS
Toy::Error::Error(): type(UNKNOWN) {}

void		Toy::Error::setType(enum ErrorType type) {
  this->type = type; }

std::string	Toy::Error::what() const {
  if (type == PICTURE)
    return "bad new illustration";
  else if (type == SPEAK)
    return "wrong mode";
  return "";
}

std::string	Toy::Error::where() const {
  if (type == PICTURE)
    return "setAscii";
  else if (type == SPEAK)
    return "speak_es";
  return "";
}

std::ostream & operator<<(std::ostream & os, Toy const & toy) {
  return os << toy.getName() << std::endl << toy.getAscii() << std::endl; }
