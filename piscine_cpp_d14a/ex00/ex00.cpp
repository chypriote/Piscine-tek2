#include	"ex00.hh"

//Cartes-------------------------------------------
Card::Card() {}

Card::~Card() {}

bool	Card::IsPartOfTheCrime() const {
  return _isPartOfTheCrime; }

//Weapons----------------------------------------
Weapon::Weapon(Weapon::Name name, bool bearsFP): _name(name), _fingerprint(bearsFP) {
  if (name == PartOfTheCrime)
    _isPartOfTheCrime = true;
  _isPartOfTheCrime = false;
}

Weapon::~Weapon() {}

bool	Weapon::BearsFingerprints() const {
  return _fingerprint; }

//Suspects--------------------------------------
Suspect::Suspect(Suspect::Name name, bool isLying): _name(name), _lying(isLying) {
  if (name == PartOfTheCrime)
    _isPartOfTheCrime = true;
  else
    _isPartOfTheCrime = false;
}

Suspect::~Suscpect() {}

bool	Suspect::IsLying() const {
  return _lying; }

//Rooms----------------------------------------
Room::Room(Room::Name name, bool hasSP): _name(name), _passage(hasSP) {
  if (name == PartOfTheCrime)
    _isPartOfTheCrime = true;
  _isPartOfTheCrime = false;
}

Room::~Room() {}

bool	Room::HasSecretPassage() const {
  return _passage; }

//Game---------------------------------------
bool	Game::CaseSolved(Weapon* w[], Suspect *s[], Room *r[]) {
  bool	solved = true;
  if (w->_name != w->PartOfTheCrime)
    solved = false;
  if (s->_name != s->PartOfTheCrime)
    solved = false;
  if (r->_name != r->PartOfTheCrime)
    solved = false;
  return solved;
}
