#include	<cstdlib>
#include	<fstream>
#include	"sickkoala.h"
#include	"koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
  if (name.empty())
    std::cerr << "The Nurse must have a name !" << std::endl;
  else
    {
      this->name = name;
      this->work = false;
      this->say("Je suis le Dr." + name + " ! Comment Kreoggez-vous ?");
    }
}

KoalaDoctor::~KoalaDoctor()
{
}

std::string	KoalaDoctor::getName()
{
  return this->name;
}

void	KoalaDoctor::say(std::string str)
{
  std::cout << "Dr." << this->name << ": " << str << std::endl;
}

void	KoalaDoctor::timeCheck()
{
  if (!this->work)
    this->say("Je commence le travail !");
  else
    this->say("Je rentre dans ma foret d'eucalyptus !");
  this->work = !this->work;
}

void	KoalaDoctor::diagnose(SickKoala *koala)
{
  this->say("Alors, qu'est-ce qui vous goerk, Mr." + koala->getName() + " ?");
  koala->poke();
  std::string	filename = koala->getName() + ".report";
  std::fstream	file(filename.data(), std::fstream::out | std::fstream::trunc);

  if (file)
    {
      std::string	drug;
      std::string	needle[5] = {"mars", "Buronzand", "Viagra", "Extasy", "Feuille d'eucalyptus"};
      drug = needle[random() % 5].data();
      file.write(drug.data(), drug.length());
      file.close();
    }
}
