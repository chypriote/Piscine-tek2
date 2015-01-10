#include	<string>
#include	<iostream>
#include	"sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  if (name.empty())
    std::cerr << "The Koala must have a name !" << std::endl;
  else
    this->name = name;
}

SickKoala::~SickKoala()
{
  this->say("Kreooogg !! Je suis gueriiii !");
}

void	SickKoala::say(std::string str)
{
  std::cout << "Mr." << this->name << ": " << str << std::endl;  
}

std::string	SickKoala::getName()
{
  return this->name;
}

void	SickKoala::poke()
{
  this->say("Gooeeeeerrk !! :'(");
}

bool	SickKoala::takeDrug(std::string needle)
{
  if (!needle.compare("Buronzand"))
    {
      this->say("Et la fatigue a fait son temps !");
      return true;
    }
  int	i = 0;
  while (needle[i])
    {
      needle[i] = tolower(needle[i]);
      i++;
    }
  if (!needle.compare("mars"))
    {
      this->say("Mars, et ca Kreog !");
      return true;
    }
  this->say("Goerk !");
  return false;
}

void	SickKoala::overDrive(std::string str)
{
  unsigned int	n;
  
  while ((n = str.find("Kreog !")))
    str.replace(n, 7, "1337 !", 0, 6);
  this->say(str);
}
