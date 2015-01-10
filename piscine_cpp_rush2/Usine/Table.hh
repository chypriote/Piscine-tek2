#ifndef		TABLE_H_
#define		TABLE_H_

#include	"ITable.hh"

class	Table : public ITable {
protected:
  int		_count;
  int		_size;
  Object**	_list;

public:
  Table();
  ~Table();

  virtual int		getCount() const;
  virtual int		getSize() const;

  virtual bool		put(Object *);
  virtual Object*	take();
  virtual Object*	take(int);
  virtual Object**	look();
  virtual void		collapse();
};

#endif
