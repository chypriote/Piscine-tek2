#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	"String.h"

static	void	assign_c(struct String *this, char const *s);
static	void	assign_s(struct String *this, struct String const *str);
static	void	append_c(struct String *this, char const *ap);
static	void	append_s(struct String *this, struct String const *ap);
static	char	at(struct String *this, size_t pos);
static	void	clear(struct String *this);
static	int	size(struct String *this);
static	int	compare_s(struct String *this, struct String const *str);
static	int	compare_c(String *this, char const *str);
static	size_t	copy(struct String *this, char *s, size_t n, size_t pos);
static	char const* c_str(struct String *this);
static	int	empty(struct String *this);
static	int	find_s(struct String *this, struct String const *str, size_t pos);
static	int	find_c(struct String *this, char const *str, size_t pos);
static	void	insert_c(struct String *this, size_t pos, char const *str);
static	void	insert_s(struct String *this, size_t pos, struct String const *str);
static	int	to_int(struct String *this);
static	void	aff(struct String *this);

void		StringInit(struct String *this, char const *s)
{
  this->str = (char *)s;
  this->assign_c = &assign_c;
  this->assign_s = &assign_s;
  this->append_c = &append_c;
  this->append_s = &append_s;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
  this->compare_c = &compare_c;
  this->compare_s = &compare_s;
  this->copy = &copy;
  this->c_str = &c_str;
  this->empty = &empty;
  this->find_s = &find_s;
  this->find_c = &find_c;
  this->insert_c = &insert_c;
  this->insert_s = &insert_s;
  this->to_int = &to_int;
  this->aff = &aff;
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
  this->str = "\0";
}

static	int	size(String *this)
{
  if (this->str)
    return strlen(this->str);
  return -1;
}

static	int	compare_s(String *this, String const *str)
{
  return strcmp(this->str, str->str);
}

static	int	compare_c(String *this, char const *str)
{
  return strcmp(this->str, (char *)str);
}

static	size_t	copy(struct String *this, char *s, size_t n, size_t pos)
{
  size_t	i;

  i = 0;
  if (this->str && s)
    while ((int)pos < this->size(this) && n != 0)
      {
	s[i] = this->str[pos];
	pos++;
	i++;
	n--;
      }
  return i;
}

static	char const *c_str(String *this)
{
  return (char const *)this->str;
}

static	int	empty(String *this)
{
  if (this->size(this) > 0)
    return -1;
  return 1;
}

static	int	find_c(String *this, char const *str, size_t pos)
{
  char		*find;
  
  if (this->size(this) > (int)pos)
    {
      find = strstr(&this->str[pos], str);
      if (find)
	return find - this->str;
    }
  return -1;
}

static	int	find_s(String *this, const String *str, size_t pos)
{
  return find_c(this, str->str, pos);
}

static	void	insert_c(String *this, size_t pos, char const *str)
{
  if ((int)pos > this->size(this))
    append_c(this, str);
}

static	void	insert_s(String *this, size_t pos, String const *str)
{
  insert_c(this, pos, str->str);
}

static	int	to_int(String *this)
{
  return atoi(this->str);
}

static	void	aff(String *this)
{
  write(1, this->str, this->size(this));
}
