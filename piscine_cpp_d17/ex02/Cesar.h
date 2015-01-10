#ifndef		CESAR_H_
#define		CESAR_H_

#include	<iostream>
#include	"IEncryptionMethod.h"

class	Cesar : public IEncryptionMethod {
protected:
  int	_shift;

public:
  Cesar();
  virtual ~Cesar();

  void	encryptChar(char);
  void	decryptChar(char);
  void	reset();
};

#endif
