#ifndef		ONETIME_H_
#define		ONETIME_H_

#include	<iostream>
#include	"IEncryptionMethod.h"

class	OneTime : public IEncryptionMethod {
 protected:
  std::string	_key;
  int		_id;

 public:
  OneTime(std::string const&);
  virtual ~OneTime();

  void	encryptChar(char);
  void	decryptChar(char);
  void	reset();
};

#endif
