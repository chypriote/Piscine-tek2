#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"String.h"

static void	assign_c(struct String *this, char const *s);
static void	assign_s(struct String *this, struct String const *str);
static void	append_c(struct String *this, char const *ap);
static void	append_s(struct String *this, struct String const *ap);


void		StringInit(String *this, char const *s)
{
  this->str = (char *)s;
  this->assign_c = &assign_c;
  this->assign_s = &assign_s;
  this->append_c = &append_c;
  this->append_s = &append_s;
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

static	void	append_c(String *this, char const *ap)
{
  char		*str = strdup(this->str);
  char		*add;
  if (ap)
    add = strdup(ap);
    this->str = strcat(str, add);
}

static	void	append_s(String *this, String const *ap)
{
  append_c(this, ap->str);
}
