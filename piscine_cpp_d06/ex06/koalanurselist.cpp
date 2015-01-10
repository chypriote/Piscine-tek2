#include	"koalanurselist.h"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse)
{
  this->nurse = nurse;
  this->next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool	KoalaNurseList::isEnd()
{
  return !(bool) this->next;
}

void	KoalaNurseList::append(KoalaNurseList *nurse)
{
  if (this->isEnd())
    this->next = nurse;
  else
    this->next->append(nurse);
}

KoalaNurse	*KoalaNurseList::getFromID(int id)
{
  if (this->nurse && this->nurse->id == id)
    return this->nurse;
  else if (this->next)
    return this->next->getFromID(id);
  return NULL;
}

KoalaNurseList	*KoalaNurseList::remove(KoalaNurseList *nurse)
{
  KoalaNurseList	*tmp = this;
  KoalaNurseList	*old = NULL;
  
  while (tmp)
    {
      if (tmp == nurse)
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

KoalaNurseList	*KoalaNurseList::removeFromID(int id)
{
  KoalaNurseList	*tmp = this;
  KoalaNurseList	*old = NULL;

  while (tmp)
    {
      if (tmp->nurse->getID() == id)
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

void	KoalaNurseList::dump()
{
  KoalaNurseList *tmp = this;
  
  while (tmp)
    {
      if (tmp->next)
	std::cout << tmp->nurse->getID() << ", ";
      else
	std::cout << tmp->nurse->getID() << ".";
      tmp = tmp->next;
    }
  std::cout << std::endl;
}
