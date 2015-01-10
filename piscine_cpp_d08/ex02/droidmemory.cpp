#include "droidmemory.hh"

//-----------------------------DroidMemory-----------------------------//
DroidMemory::DroidMemory() : exp(0) {
  fingerPrint = random(); }

DroidMemory::~DroidMemory()
{ }

//-----------------------------DroidMemory: getters-----------------------------//
size_t			DroidMemory::getFingerPrint() const {
  return fingerPrint; }

size_t			DroidMemory::getExp() const {
  return exp; }

//-----------------------------DroidMemory: setters-----------------------------//
void			DroidMemory::setFingerPrint(size_t fingerPrint) {
  this->fingerPrint = fingerPrint; }

void			DroidMemory::setExp(size_t exp) {
  this->exp = exp; }

//-----------------------------DroidMemory: operators-----------------------------//
DroidMemory&		DroidMemory::operator<<(DroidMemory const & memory) {
  DroidMemory::fusion(*this, *this, memory);
  return *this;
}

DroidMemory const&	DroidMemory::operator>>(DroidMemory & memory) const {
  DroidMemory::fusion(memory, *this, memory);
  return *this;
}

DroidMemory&		DroidMemory::operator+=(DroidMemory const & memory) {
  DroidMemory::fusion(*this, *this, memory);
  return *this;
}

DroidMemory&		 DroidMemory::operator+=(size_t exp)
{
  DroidMemory	memory;

  memory.exp = exp;
  memory.fingerPrint = exp;
  DroidMemory::fusion(*this, *this, memory);
  return *this;
}

DroidMemory&		DroidMemory::operator+(DroidMemory const & memory) const
{
  DroidMemory	*tmp = new DroidMemory();

  DroidMemory::fusion(*tmp, *this, memory);
  return *tmp;
}

DroidMemory&		DroidMemory::operator+(size_t exp) const
{
  DroidMemory	memory;
  DroidMemory	*tmp = new DroidMemory();

  memory.exp = exp;
  memory.fingerPrint = exp;
  DroidMemory::fusion(*tmp, *this, memory);
  return *tmp;
}

//-------------------------Memory comparator----------------------//
bool			DroidMemory::operator==(DroidMemory const &memory) const {
  return ((fingerPrint == memory.fingerPrint) && (exp == memory.exp));
}

bool			DroidMemory::operator!=(DroidMemory const &memory) const {
  return !(*this == memory);
}

bool			DroidMemory::operator<(DroidMemory const &memory) const {
  return (exp < memory.exp); }

bool			DroidMemory::operator>(DroidMemory const &memory) const {
  return (exp > memory.exp); }

bool			DroidMemory::operator<=(DroidMemory const &memory) const {
  return (exp <= memory.exp); }

bool			DroidMemory::operator>=(DroidMemory const &memory) const {
  return (exp >= memory.exp); }

//-------------------------Size comparator----------------------//
bool			DroidMemory::operator<(size_t size) const {
  return (exp < size); }

bool			DroidMemory::operator>(size_t size) const {
  return (exp > size); }

bool			DroidMemory::operator<=(size_t size) const {
  return (exp <= size); }

bool			DroidMemory::operator>=(size_t size) const {
  return (exp >= size); }

//-------------------------------------------------------------------------//
void			DroidMemory::fusion(DroidMemory &dest, DroidMemory const &memory1, DroidMemory const &memory2) {
  dest.exp = memory1.exp + memory2.exp;
  dest.fingerPrint = memory1.fingerPrint ^ memory2.fingerPrint;
}

std::ostream&		operator<<(std::ostream & os, DroidMemory const & memory) {
  return os << "DroidMemory '" << memory.getFingerPrint() << "', " << memory.getExp();
}
