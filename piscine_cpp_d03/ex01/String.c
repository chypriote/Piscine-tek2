#include	<stdlib.h>
#include	<stdio.h>
#include	"String.h"

static void	assign_s(struct String *this, struct String const *str);
static void	assign_c(struct String *this, char const *s);

void		StringInit(String *this, char const *s)
{
  this->str = (char *)s;
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
}

void		StringDestroy(String *this)
{
  if (this->str)
    free(this->str);
}

static	void	assign_c(String *this, char const *s)
{
  this->str = (char *)s;
}

static	void	assign_s(String *this, String const *str)
{
  assign_c(this, str->str);
}
