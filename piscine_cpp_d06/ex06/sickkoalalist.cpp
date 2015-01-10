#include	"sickkoalalist.h"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
  this->koala = koala;
  this->next = NULL;
}

SickKoalaList::~SickKoalaList()
{
}

bool	SickKoalaList::isEnd()
{
  return !(bool) this->next;
}

void	SickKoalaList::append(SickKoalaList *koala)
{
  if (this->isEnd())
    this->next = koala;
  else
    this->next->append(koala);
}

SickKoala	*SickKoalaList::getFromName(std::string name)
{
  if (this->koala && this->koala->name == name)
    return this->koala;
  else if (this->next)
    return this->next->getFromName(name);
  return NULL;
}

SickKoalaList	*SickKoalaList::remove(SickKoalaList *koala)
{
  SickKoalaList	*tmp = this;
  SickKoalaList	*old = NULL;

  while (tmp)
    {
      if (tmp == koala)
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

SickKoalaList	*SickKoalaList::removeFromName(std::string name)
{
  SickKoalaList *tmp = this;
  SickKoalaList	*old = NULL;

  while (tmp)
    {
      if (tmp->koala->getName() == name)
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

void	SickKoalaList::dump()
{
  SickKoalaList	*tmp = this;
  
  while (tmp)
      {
	if (tmp->next)
	  std::cout << tmp->koala->getName() << ", ";
	else
	  std::cout << tmp->koala->getName() << ".";
	tmp = tmp->next;
      }
  std::cout << std::endl;
}

SickKoalaList	*SickKoalaList::getContent()
{
  return this->koala;
}

SickKoalaList	*SickKoalaList::getNext()
{
  return this->next;
}
