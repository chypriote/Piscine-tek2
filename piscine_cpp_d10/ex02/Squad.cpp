#include	"Squad.hh"

Squad::Squad() : _count(0), _size(10) {
  _unit = new ISpaceMarine*[_size];
  int i = 0;
  while (i < _size)
    _unit[i++] = NULL;
}

Squad::Squad(Squad const& squad) {
  _count = squad._count;
  _size = squad._size;
  _unit = new ISpaceMarine*[_size];
  int i = 0;
  while (i < _size) {
    _unit[i] = NULL;
    if (squad._unit[i])
      _unit[i] = squad._unit[i]->clone();
    i++;
  }
}

Squad::~Squad() {
  int i = 0;
  while (i < (int) _count)
    delete _unit[i++];
  delete[] _unit;
}

//-------------------------Squad: getters-------------------------------//
int		Squad::getCount() const {
  return _count; }

ISpaceMarine*	Squad::getUnit(int nb)
{
  if (nb > _size || nb < 0)
    return NULL;
  return _unit[nb];
}

//-------------------------Squad: functions-------------------------------//
int		Squad::push(ISpaceMarine *marine)
{
  if (marine)
    {
      if (_count >= _size)
	resizeUnit();
      int i = 0;
      while (i < _count)
	if (_unit[i++] == marine)
	  return _count;
      _unit[_count++] = marine;
    }
  return _count;
}

void		Squad::resizeUnit() {
  size_t new_size = _size * 1.5;
  ISpaceMarine **new_unit = new ISpaceMarine *[new_size];
  int i = 0;
  while (i < (int) _size) {
    new_unit[i] = _unit[i];
    i++;
  }
  while (i < (int) new_size)
    new_unit[i++] = NULL;
  delete[] _unit;
  _unit = new_unit;
  _size = new_size;
}
