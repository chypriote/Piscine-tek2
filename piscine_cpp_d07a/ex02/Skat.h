#ifndef		SKAT_H_
#define		SKAT_H_

#include	<string>
#include	<iostream>

class Skat {
 public:
  Skat(std::string const& name = "bob", int stimPaks = 15);
  ~Skat();

 public:
  int&			stimPaks();
  std::string const&	name();

 public:
  void			shareStimPaks(int, int&);
  void			addStimPaks(unsigned int);
  void			useStimPaks();
  void			status() const;

 private:
  std::string		_name;
  int			_stimPacks;
};

#endif
