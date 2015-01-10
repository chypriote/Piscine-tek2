#ifndef		TOY_H_
#define		TOY_H_

#include	"Picture.h"

class	Toy {
 public:
  class Error {
  public:
    enum ErrorType {
      UNKNOWN,
      PICTURE,
      SPEAK
    }	ErrorType;
    
    enum ErrorType	type;

    Error();
    void		setType(enum ErrorType);
    std::string		what() const;
    std::string		where() const;
  };

enum	ToyType {
  BASIC_TOY,
  ALIEN,
  BUZZ,
  WOODY
}	ToyType;

 protected:
  enum ToyType	_type;
  std::string	_name;
  Picture	_picture;
  Error		_error;

 public:
  Toy();
  Toy(enum ToyType, std::string const&, std::string const&);
  Toy(Toy const&);
  virtual ~Toy();
  Toy&		operator=(Toy const&);

  int			getType() const;
  std::string const&	getName() const;
  std::string const&	getAscii() const;

  void			setName(std::string const&);
  bool			setAscii(std::string const& filename);

  virtual bool		speak(std::string const&);
  virtual bool		speak_es(std::string const&);
  virtual Toy&		operator<<(std::string const&);
  Toy::Error const&	getLastError() const;
};

std::ostream&	operator<<(std::ostream&, Toy const&);

#endif
