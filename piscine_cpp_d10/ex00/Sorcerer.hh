#ifndef		SORCERER_H_
#define		SORCERER_H_

#include	<string>
#include	<iostream>

#include	"Victim.hh"

class Sorcerer {
protected:
  std::string	_name;
  std::string	_title;

public:
  explicit Sorcerer(std::string name, std::string title);
  ~Sorcerer();

public:
  std::string const&	getName() const;
  std::string const&	getTitle() const;

  void			polymorph(Victim const&) const;
protected:
  virtual void		sayCreation();
  virtual void		sayDestruction();
};

std::ostream&		operator<<(std::ostream&, Sorcerer const&);

#endif
