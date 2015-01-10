#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"String.h"

static	void	assign_c(struct String *this, char const *s);
static	void	assign_s(struct String *this, struct String const *str);
static	void	append_c(struct String *this, char const *ap);
static	void	append_s(struct String *this, struct String const *ap);
static	char	at(struct String *this, size_t pos);
static	void	clear(struct String *this);
static	int	size(struct String *this);

void		StringInit(String *this, char const *s)
{
  this->str = (char *)s;
  this->assign_c = &assign_c;
  this->assign_s = &assign_s;
  this->append_c = &append_c;
  this->append_s = &append_s;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
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

static	char	at(String *this, size_t pos)
{
  if (this->str[pos])
    return this->str[pos];
  return -1;
}

static	void	clear(String *this)
{
  this->str = strdup("\0");
}

static	int	size(String *this)
{
  if (strlen(this->str))
    return strlen(this->str);
  return -1;
}
