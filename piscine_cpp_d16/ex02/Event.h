#ifndef		EVENT_H_
#define		EVENT_H_

#include	<string>

class Event {
 public:
  Event();
  Event(const Event &);
  Event(unsigned int, const std::string &);
  ~Event();
  
 public:
  unsigned int		getTime() const;
  const std::string&	getEvent() const;
  void			setTime(unsigned int);
  void			setEvent(const std::string &);

 public:
  Event&	operator=(const Event &);
  bool		operator<(const Event &);
  bool		operator>(const Event &);
  bool		operator==(const Event &);
  bool		operator<(unsigned int);
  bool		operator>(unsigned int);
  bool		operator==(unsigned int);

 private:
  unsigned int	_time;
  std::string	_event;
};

#endif
