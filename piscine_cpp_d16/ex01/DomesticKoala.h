#ifndef		DOMESTICKOALA_H_
#define		DOMESTICKOALA_H_

#include	<vector>
#include	"KoalaAction.h"

class DomesticKoala {
 public:
  DomesticKoala();
  DomesticKoala(const DomesticKoala &);
  DomesticKoala(KoalaAction &);
  ~DomesticKoala();
  typedef void (KoalaAction::*methodPointer_t)(const std::string &);

 public:
  std::vector<methodPointer_t> const *	getActions() const;
  void					learnAction(unsigned char, methodPointer_t);
  void					unlearnAction(unsigned char);
  void					doAction(unsigned char, const std::string &);
  void					setKoalaAction(KoalaAction &);
		
 public:
  DomesticKoala				&operator=(const DomesticKoala &);

 private:
  std::vector<methodPointer_t>		_methods;
  std::vector<unsigned char>		_orders;
  KoalaAction				*_ka;
};

#endif
