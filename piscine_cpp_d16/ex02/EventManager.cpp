#include <iostream>
#include "EventManager.h"

//-----------------------------------------------------------
// Constructor / Destructor
//-----------------------------------------------------------
EventManager::EventManager()
  : _currentTime(0), _eventsList()
{
}

EventManager::EventManager(const EventManager &ref)
  : _currentTime(ref._currentTime),
    _eventsList(ref._eventsList)
{
}

EventManager::~EventManager()
{
}

//-----------------------------------------------------------
// Utilities
//-----------------------------------------------------------
void EventManager::addEvent(const Event &e)
{
  if (e.getTime() <= this->_currentTime)
    return;
  std::list<Event>::iterator iter;
  for (iter = this->_eventsList.begin(); iter != this->_eventsList.end(); iter++)
    {
      if ((*iter).getTime() > e.getTime())
	{
	  this->_eventsList.insert(iter, 1, e);
	  return;
	}
    }
  this->_eventsList.push_back(e);
}

void EventManager::removeEventsAt(unsigned int t)
{
  std::list<Event>::const_iterator iter;
  for (iter = this->_eventsList.begin(); iter != this->_eventsList.end(); iter++)
    if ((*iter).getTime() == t)
      this->_eventsList.remove(*iter);
}

void EventManager::dumpEvents() const
{
  std::list<Event>::const_iterator iter;
  for (iter = this->_eventsList.begin(); iter != this->_eventsList.end(); iter++)
    std::cout << (*iter).getTime() << ": " << (*iter).getEvent() << std::endl;
}

void EventManager::dumpEventAt(unsigned int t) const
{
  std::list<Event>::const_iterator iter;
  for (iter = this->_eventsList.begin(); iter != this->_eventsList.end(); iter++)
    if ((*iter).getTime() == t)
      std::cout << (*iter).getTime() << ": " << (*iter).getEvent() << std::endl;
}

void EventManager::addTime(unsigned int t)
{
  this->_currentTime += t;

  std::list<Event>::const_iterator iter;
  for (iter = this->_eventsList.begin(); iter != this->_eventsList.end(); iter++)
    {
      if ((*iter).getTime() <= this->_currentTime)
	{
	  std::cout << (*iter).getEvent() << std::endl;
	  this->_eventsList.remove(*iter);
	}
    }
}

void EventManager::addEventList(std::list<Event> &l)
{
  std::list<Event>::iterator iter;
  for (iter = l.begin(); iter != l.end(); iter++)
    addEvent(*iter);
}

//-----------------------------------------------------------
// Operators
//-----------------------------------------------------------
EventManager &EventManager::operator=(const EventManager &other)
{
  this->_currentTime = other._currentTime;
  this->_eventsList = other._eventsList;
  return *this;
}
