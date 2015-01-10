#ifndef		EVENTMANAGER_H_
#define		EVENTMANAGER_H_

#include	<list>
#include	"Event.h"

class	EventManager {
 public:
  EventManager();
  EventManager(const EventManager &);
  ~EventManager();

 public:
  void		addEvent(const Event &);
  void		removeEventsAt(unsigned int);
  void		dumpEvents() const;
  void		dumpEventAt(unsigned int) const;
  void		addTime(unsigned int);
  void		addEventList(std::list<Event> &);

 public:
  EventManager&	operator=(const EventManager &);

 private:
  unsigned int		_currentTime;
  std::list<Event>	_eventsList;
};

#endif
