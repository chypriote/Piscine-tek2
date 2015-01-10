#ifndef		DROID_H_
#define		DROID_H_

#include	<string>
#include	<iostream>

class Droid {
private:

  std::string		Id;
  size_t		Energy;
  size_t const		Attack;
  size_t const		Toughness;
  std::string		*Status;

public:
  Droid(std::string Id = "");
  Droid(Droid const&);
  ~Droid();

  std::string		getId() const;
  size_t		getEnergy() const;
  size_t		getAttack() const;
  size_t		getToughness() const;
  std::string		*getStatus() const;

  void			setId(std::string);
  void			setEnergy(size_t);
  void			setStatus(std::string *);

  bool		operator==(Droid const &) const;
  bool		operator!=(Droid const &) const;
  Droid&	operator=(Droid const &);
  Droid&	operator<<(size_t&);
};

std::ostream&	operator<<(std::ostream&, Droid const &);

#endif
