#ifndef		DROIDMEMORY_H_
#define		DROIDMEMORY_H_

#include	<string>
#include	<iostream>
#include	<cstdlib>

class DroidMemory {
private:
  size_t	fingerPrint;
  size_t	exp;

public:
  DroidMemory();
  ~DroidMemory();

  size_t	getFingerPrint() const;
  size_t	getExp() const;
  
  void		setFingerPrint(size_t);
  void		setExp(size_t);

  DroidMemory&	operator<<(DroidMemory const&);
  DroidMemory const& operator>>(DroidMemory&) const;
  DroidMemory&	operator+=(DroidMemory const&);
  DroidMemory&	operator+=(size_t);
  DroidMemory&	operator+(DroidMemory const&) const;
  DroidMemory&	operator+(size_t) const;

  bool		operator==(DroidMemory const&) const;
  bool		operator!=(DroidMemory const&) const;
  bool		operator<(DroidMemory const&) const;
  bool		operator>(DroidMemory const&) const;
  bool		operator<=(DroidMemory const&) const;
  bool		operator>=(DroidMemory const&) const;

  bool		operator<(size_t) const;
  bool		operator>(size_t) const;
  bool		operator<=(size_t) const;
  bool		operator>=(size_t) const;


private:
  static void fusion(DroidMemory&, DroidMemory const&, DroidMemory const&);
};

std::ostream & operator<<(std::ostream & os, DroidMemory const & memory);

#endif
