#include	<string>
#include	<fstream>
#include	<iostream>
#include	"sickkoala.h"
#include	"koalanurse.h"

KoalaNurse::KoalaNurse(int id)
{
  if (id == 0)
    std::cerr << "The Nurse must have an ID !" << std::endl;
  else
    {
      this->id = id;
      this->work = false;
    }
}

KoalaNurse::~KoalaNurse()
{
  this->say("Enfin un peu de repos !");
}

void	KoalaNurse::say(std::string str)
{
  std::cout << "Nurse " << this->id << ": " << str << std::endl;
}

void	KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
  koala->takeDrug(drug);
}

std::string	KoalaNurse::readReport(std::string filename)
{
  int		i = filename.find(".report");
  if (i == (int) std::string::npos)
    return "";
  std::fstream	file(filename.data(), std::ios::in);

  if (file)
    {
      std::string	drug;
      char		str[100];
      std::string	koala = filename.substr(0,i);

      str[file.readsome(str, 100)] = 0;
      drug = str;
      this->say(std::string("Kreog ! Il faut donner un " + drug + " a Mr." + koala + " !"));
      file.close();
      return drug;
    }
  return "";
}

void	KoalaNurse::timeCheck()
{
  if (!this->work)
    this->say("Je commence le travail !");
  else
    this->say("Je rentre dans ma foret d'eucalyptus !");
  this->work = !this->work;
}
