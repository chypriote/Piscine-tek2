#ifndef		PICTURE_H_
#define		PICTURE_H_

#include	<string>
#include	<iostream>
#include	<fstream>
#include	<sstream>

class	Picture {
 public:
  std::string	data;

  Picture();
  Picture(std::string const& file);
  virtual ~Picture();
  bool		getPictureFromFile(std::string const& file = "");
  Picture&	operator=(Picture const&);
};

#endif
