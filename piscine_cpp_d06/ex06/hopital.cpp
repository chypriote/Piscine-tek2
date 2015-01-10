#include "hopital.h"

Hospital::Hospital()
{
  this->koalas = NULL;
  this->nurses = NULL;
  this->doctors = NULL;
}

Hospital::~Hospital()
{
}

void	Hospital::action(std::string action)
{
  std::cout << "[HOPITAL] " << action << std::endl;
}

void	Hospital::addSick(SickKoalaList* koala)
{
  if (this->koalas && this->koalas->getFromName(koala->getName()))
    return ;
  if (this->koalas)
    this->koalas->append(koala);
  else
    this->koalas = koala;
  this->action(std::string("SickKoala ") + koala->getName() + " just arrived !");
}

void Hospital::addNurse(KoalaNurseList* nurse)
{
  std::ostringstream oss;

  if (this->nurses && this->nurses->getFromID(nurse->getID()))
    return ;
  if (this->nurses)
    this->nurses->append(nurse);
  else
    this->nurses = nurse;
  oss << nurse->getID();
  this->action(std::string("Nurse ") + oss.str() + " just arrived !");
  nurse->timeCheck();
}

void Hospital::addDoctor(KoalaDoctorList* doctor)
{
  if (this->doctors && this->doctors->getFromName(doctor->getName()))
    return ;
  if (this->doctors)
    this->doctors->append(doctor);
  else
    this->doctors = doctor;
  this->action(doctor->getName() + " just arrived !");
  doctor->timeCheck();
}

void Hospital::run()
{
  this->action("Ouverture");
  this->doctors->dump();
  this->nurses->dump();
  this->koalas->dump();
  std::cout << std::endl;
  
  this->doctors->getFromName("Cox")->diagnose(this->koalas->getFromName("Ganepar"));
  this->nurses->getFromID(1)->giveDrug(this->nurses->getFromID(1)->readReport("Ganepar.report"), this->koalas->getFromName("Ganepar"));
  this->koalas = this->koalas->removeFromName("Ganepar");
  
  this->doctors->getFromName("House")->diagnose(this->koalas->getFromName("Scarface"));
  this->nurses->getFromID(2)->giveDrug(this->nurses->getFromID(2)->readReport("Scarface.report"), this->koalas->getFromName("Scarface"));
  this->koalas = this->koalas->removeFromName("Scarface");
	
  this->doctors->getFromName("Boudur-Oulot")->diagnose(this->koalas->getFromName("RedFace"));
  this->nurses->getFromID(1)->giveDrug(this->nurses->getFromID(1)->readReport("RedFace.report"), this->koalas->getFromName("RedFace"));
  this->koalas = this->koalas->removeFromName("RedFace");
  
  this->doctors->getFromName("Cox")->diagnose(this->koalas->getFromName("Falter"));
  this->nurses->getFromID(2)->giveDrug(this->nurses->getFromID(2)->readReport("Falter.report"), this->koalas->getFromName("Falter"));
  this->koalas = this->koalas->removeFromName("Falter");
  
  this->nurses->getFromID(1)->timeCheck();
  this->nurses = this->nurses->removeFromID(1);
  this->nurses->getFromID(2)->timeCheck();
  this->nurses = this->nurses->removeFromID(2);
  
  this->doctors->getFromName("Cox")->timeCheck();
  this->doctors = this->doctors->removeFromName("Cox");
  this->doctors->getFromName("House")->timeCheck();
  this->doctors = this->doctors->removeFromName("House");
  this->doctors->getFromName("Boudur-Oulot")->timeCheck();
  this->doctors = this->doctors->removeFromName("Boudur-Oulot");
  this->action("Fermeture");
}
