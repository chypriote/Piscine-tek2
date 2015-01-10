#include	"Table.hh"
#include	<cstdio>

Table::Table() : _count(0), _size(10) {
  int	i = 0;
  _list = new Object*[_size];
  while (i != _size)
    _list[i++] = NULL;
}

Table::~Table() {}

//Table: getters--------------------------------
int		Table::getCount() const {
  return _count; }

int		Table::getSize() const {
  return _size; }

//Table: actions--------------------------------
bool		Table::put(Object *object) {
  if (object) {
    if (_count < _size) {
      int i = 0;
      while (i != _size && _list[i])
	i++;
      _list[i] = object;
      _count++;
      return true;
    }
    else
      collapse();
  }
  return false;
}

Object*		Table::take() {
  return take(0); }

Object*		Table::take(int id) {
  if (_list) {
    if (_list[id] && id < _size) {
      Object *obj = _list[id];
      _list[id]->isTaken();
      _list[id] = NULL;
      _count--;
      return obj;
    }
    return NULL;
  }
  std::cout << "There is no table !" << std::endl;
  return NULL;
}

Object**	Table::look() {
  if (_list) {
    Object	**list = new Object*[_count];
    int	i = 0;
    int	n = 0;
    while (i != _size) {
      if (_list[i]) {
	list[n] = _list[i];
	n++;
      }
      i++;
    }
    return list;
  }
  std::cout << "There is no table !" << std::endl;
  return NULL;
}

void		Table::collapse() {
  std::cout << "  /-----------------------------------------------------/" << std::endl;
  std::cout << " / Too many objects on the table, the table ";
  std::cout << "\033[1;30;31m" << "explosed" << "\033[1;30;00m" << " ! /" << std::endl;
  std::cout << "/-----------------------------------------------------/" << std::endl;
  _list = NULL;
  _count = 0;
  _size = 0;
}
