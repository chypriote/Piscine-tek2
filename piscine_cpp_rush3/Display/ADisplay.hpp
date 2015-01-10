#ifndef		ADISPLAY_H_
#define		ADISPLAY_H_

#include	<map>
#include	"IModuleDisplay.hpp"

class	ADisplay : public IModuleDisplay {
public:
  ADisplay() {}
  virtual ~ADisplay() {}

  virtual void		show(bool);
  virtual void		showCurses() = 0;
  //  virtual void		showQt() = 0;

  virtual void		addToMap(std::string, std::string);

protected:
  std::map<std::string, std::string>	_map;
  bool		_useQt;

};

#endif	/*	ADISPLAY_H_	*/
