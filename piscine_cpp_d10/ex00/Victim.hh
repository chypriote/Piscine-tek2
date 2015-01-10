#ifndef		VICTIM_H_
#define		VICTIM_H_

#include	<string>
#include	<iostream>

class Victim {
protected:
  std::string	_name;

public:
  explicit Victim(std::string name);
  ~Victim();

public:
  std::string const&	getName() const;

  void			getPolymorphed() const;
protected:
  virtual void		sayCreation();
  virtual void		sayDestruction();
  virtual void		sayPolymorph() const;
};

std::ostream&		operator<<(std::ostream&, Victim const&);

#endif
