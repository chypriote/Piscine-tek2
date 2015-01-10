#ifndef		STRING_H_
#define		STRING_H_

typedef	struct	String
{
  char		*str;

  void		(*assign_s)(struct String *this, struct String const *str);
  void		(*assign_c)(struct String *this, char const *s);
  void		(*append_s)(struct String *this, struct String const *ap);
  void		(*append_c)(struct String *this, char const *ap);
}		String;

void		StringInit(String *this, char const *s);
void		StringDestroy(String *this);

#endif
