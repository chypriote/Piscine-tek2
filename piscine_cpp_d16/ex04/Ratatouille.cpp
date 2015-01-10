#include	"Ratatouille.h"


//Constructors---------------------------------------------
Ratatouille::Ratatouille() { }

Ratatouille::Ratatouille(const Ratatouille& source) {
  flux = source.flux; 
}

Ratatouille::~Ratatouille() { }


Ratatouille&	Ratatouille::operator=(const Ratatouille& source) {
  flux = source.flux;
  return *this;
}

//AddFunctions---------------------------------------------
Ratatouille&	Ratatouille::addVegetable(unsigned char vegetable) {
  std::stringstream	s;
  s << flux << vegetable;
  flux = s.str();
  return *this;
}

Ratatouille&	Ratatouille::addCondiment(unsigned int condiment) {
  std::stringstream	s;
  s << flux << condiment;
  flux = s.str();
  return *this;
}

Ratatouille&	Ratatouille::addSpice(double spice) {
  std::stringstream	s;
  s << flux << spice;
  flux = s.str();
  return *this;
}

Ratatouille&	Ratatouille::addSauce(std::string const& sauce) {
  std::stringstream	s;
  s << flux << sauce;
  flux = s.str();
  return *this;
}

std::string	Ratatouille::kooc() {
  return flux; }
