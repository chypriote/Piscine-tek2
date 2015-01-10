#include "carrier.hh"

//--------------------------------Carrier---------------------------//
Carrier::Carrier(std::string serial) : Id(serial), Energy(300), Attack(100), Toughness(90) {
  Droids = new Droid*[5];
  int	i = 0;
  while (i < 5)
    Droids[i++] = NULL;
}

Carrier::~Carrier() {
  int i = 0;
  while (i < 5)
    {
      if (Droids[i])
	delete Droids[i];
      i++;
    }
}

//--------------------------------Carrier: getters---------------------------//
std::string Carrier::getId() const {
  return Id; }

size_t		Carrier::getEnergy() const {
  return Energy; }

size_t		Carrier::getAttack() const {
  return Attack; }

size_t		Carrier::getToughness() const {
  return Toughness; }

size_t		Carrier::getSpeed() const {
  int n = getNbDroids();
  if (n)
    return 100 - n * 10;
  return 0;
}

size_t		Carrier::getNbDroids() const {
  int	n = 0;
  int	i = 0;
  
  while (i < 5)
    {
      if (Droids[i])
	n++;
      i++;
    }
  return n;
}

//--------------------------------Carrier: setters---------------------------//
void		Carrier::setId(std::string id) {
  Id = id; }

void		Carrier::setEnergy(size_t energy) {
  Energy = energy; }

//--------------------------------Carrier: operators---------------------------//
Carrier&	Carrier::operator <<(size_t& energy) {
  if (Energy < 600)
    {
      int take = std::min(600 - Energy, energy);
      Energy += take;
      energy -= take;
  }
  return *this;
}

Carrier&	Carrier::operator <<(Droid* droid)
{
  int	i = 0;
  while (i < 5)
    {
      if (!Droids[i])
	{
	  Droids[i] = droid;
	  return *this;
	}
      i++;
    }
  return *this;
}

Carrier&	Carrier::operator >>(Droid* droid)
{
  int	i = 0;
  while (i < 5)
    {
      if (Droids[i])
	{
	  droid = Droids[i];
	  Droids[i] = NULL;
	  return *this;
	}
      i++;
    }
  return *this;
}

Carrier&	Carrier::operator ~() {
  return *this; }

Droid*&		Carrier::operator[](int position) const {
	return Droids[position];
}

std::ostream&		operator<<(std::ostream &os, Carrier const& carrier) {
  os << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
  int	i = 0;

  while (i < 5)
    {
      os << "[" << i << "] : ";
      if (carrier[i])
	os << *carrier[i];
      else
	os << "Free";
      if (i != 4)
	os << std::endl;
      i++;
    }
  return os;
}
