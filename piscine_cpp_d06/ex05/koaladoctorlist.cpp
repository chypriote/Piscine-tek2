#include	"koaladoctorlist.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor)
{
  this->doctor = doctor;
  this->next = NULL;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool	KoalaDoctorList::isEnd()
{
  return !(bool) this->next;
}

void	KoalaDoctorList::append(KoalaDoctorList *doctor)
{
  if (this->isEnd())
    this->next = doctor;
  else
    this->next->append(doctor);
}

KoalaDoctor	*KoalaDoctorList::getFromName(std::string name)
{
  if (this->doctor && this->doctor->name == name)
    return this->doctor;
  else if (this->next)
    return this->next->getFromName(name);
  return NULL;
}

KoalaDoctorList	*KoalaDoctorList::remove(KoalaDoctorList *doctor)
{
  KoalaDoctorList	*tmp = this;
  KoalaDoctorList	*old = NULL;

  while (tmp)
    {
      if (tmp == doctor)
	{
	  if (old)
	    {
	      old->next = tmp->next;
	      tmp->next = NULL;
	      return this;
	    }
	  else
	    {
	      old = tmp->next;
	      tmp->next = NULL;
	      return old;
	    }
	}
      old = tmp;
      tmp = this->next;
    }
  return NULL;
}

KoalaDoctorList	*KoalaDoctorList::removeFromName(std::string name)
{
  KoalaDoctorList	*tmp = this;
  KoalaDoctorList	*old = NULL;

  while (tmp)
    {
      if (tmp->doctor->getName() == name)
	{
	  if (old)
	    {
	      old->next = tmp->next;
	      tmp->next = NULL;
	      return this;
	    }
	  else
	    {
	      old = tmp->next;
	      tmp->next = NULL;
	      return old;
	    }
	}
      old = tmp;
      tmp = this->next;
    }
  return NULL;
}

void	KoalaDoctorList::dump()
{
  KoalaDoctorList *tmp = this;

  while (tmp)
    {
      if (tmp->next)
	std::cout << tmp->doctor->getName() << ", ";
      else
	std::cout << tmp->doctor->getName() << ".";
      tmp = tmp->next;
    }
  std::cout << std::endl;
}
