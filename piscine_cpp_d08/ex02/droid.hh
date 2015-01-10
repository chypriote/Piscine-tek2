#ifndef		DROID_H_
#define		DROID_H_

#include	<string>
#include	<iostream>
#include	"droidmemory.hh"

class Droid {
private:
  std::string		Id;
  size_t		Energy;
  size_t const		Attack;
  size_t const		Toughness;
  std::string		*Status;
  DroidMemory		*BattleData;

public:
  Droid(std::string Id);
  Droid(Droid const&);
  ~Droid();

  std::string		getId() const;
  size_t		getEnergy() const;
  size_t		getAttack() const;
  size_t		getToughness() const;
  std::string		*getStatus() const;
  DroidMemory		*getBattleData() const;

  void			setId(std::string);
  void			setEnergy(size_t);
  void			setStatus(std::string *);
  void			setBattleData(DroidMemory *);

  bool			operator==(Droid const &) const;
  bool			operator!=(Droid const &) const;
  Droid&		operator=(Droid const &);
  Droid&		operator<<(size_t&);
  bool			operator()(std::string const*, size_t);
};

std::ostream&		operator<<(std::ostream&, Droid const &);

#endif
