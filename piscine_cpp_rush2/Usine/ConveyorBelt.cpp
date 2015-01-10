#include	"ConveyorBelt.hh"

ConveyorBelt::ConveyorBelt() {
  _object = NULL; }

ConveyorBelt::~ConveyorBelt() {}


Object*	ConveyorBelt::getObject() {
  return _object; }

bool	ConveyorBelt::put(Object *obj) {
  if (obj) {
    if (!_object) {
      _object = obj;
      return true; }
  }
  return false;
}

Object	*ConveyorBelt::take() {
  if (_object) {
    Object *obj;
    obj = _object;
    _object = NULL;
    return obj;
  }
  return NULL;
}

std::string	ConveyorBelt::look() {
  if (_object)
    return _object->getTitle();
  return NULL;
}

Wrap*		ConveyorBelt::IN() {
  int	i = random() % 2;

  if (i == 1)
    return new Box;
  else
    return new GiftPaper;
}

void		ConveyorBelt::OUT() {
  Object *tmp = _object;
  _object = NULL;
  (void) tmp;
  verbose("Santa Klaus : Oh oh oh... Thk u 4 teh gift !");
}
