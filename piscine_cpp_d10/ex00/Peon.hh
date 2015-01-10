#ifndef		PEON_H_
#define		PEON_H_

#include	"Victim.hh"

class Peon : virtual public Victim {
protected:
  Peon();

public:
  explicit Peon(std::string const& name);
  ~Peon();

  void			getPolymorphed() const;
protected:
  virtual void		sayCreation();
  virtual void		sayDestruction();
  virtual void		sayPolymorph() const;
};

#endif
