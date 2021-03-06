#ifndef		TOY_H_
#define		TOY_H_

#include	"Picture.h"

class	Toy {
 public:
enum	ToyType {
  BASIC_TOY,
  ALIEN
}	ToyType;

  enum ToyType	_type;
  std::string	_name;
  Picture	_picture;

  Toy();
  Toy(enum ToyType, std::string const&, std::string const&);
  Toy(Toy const&);
  virtual ~Toy();
  Toy&		operator=(Toy const&);

  int			getType() const;
  std::string const&	getName() const;
  std::string const&	getAscii() const;

  void		setName(std::string const&);
  bool		setAscii(std::string const& filename);
};

#endif
