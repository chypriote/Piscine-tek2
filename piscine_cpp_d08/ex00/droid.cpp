#include	"droid.hh"

//--------------------------Droid-------------------------//
Droid::Droid(std::string serial) : Id(serial), Energy(50), Attack(25), Toughness(15)
{
  Status = new std::string("Standing by");
  std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid& droid) : Id(droid.Id), Energy(droid.Energy), Attack(droid.Attack), Toughness(droid.Toughness)
{
  if (droid.Status)
    Status = new std::string(*(droid.Status));
  else
    Status = new std::string("Standing by");
  std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

//--------------------------Droid: getters-------------------------//
std::string	Droid::getId() const {
  return Id; }

size_t		Droid::getEnergy() const {
  return Energy; }

size_t		Droid::getAttack() const {
  return Attack; }

size_t		Droid::getToughness() const {
  return Toughness; }

std::string	*Droid::getStatus() const {
  return Status; }


//--------------------------Droid: setters-------------------------//
void		Droid::setId(std::string id) {
  Id = id; }

void		Droid::setEnergy(size_t nrg) {
  Energy = nrg; }

void		Droid::setStatus(std::string *stat) {
  Status = stat; }

//--------------------------Droid: operators-------------------------//
bool		Droid::operator==(Droid const &droid) const {
  return (
	  (Id == droid.Id) && 
	  (Energy == droid.Energy) && 
	  (Attack == droid.Attack) && 
	  (Toughness == droid.Toughness) && 
	  (Status == droid.Status));
}

bool		Droid::operator!=(Droid const &droid) const {
  return !(*this == droid); }

Droid&		Droid::operator=(Droid const &droid) {
  Id = droid.Id;
  Energy = droid.Energy;
  delete Status;
  Status = new std::string(*(droid.Status));
  return *this;
}

Droid&		Droid::operator<<(size_t& nrg)
{
  if (Energy < 100)
    {
      int	take = std::min(100 - Energy, nrg);
      Energy += take;
      nrg -= take;
    }
  return *this;
}

std::ostream&	operator<<(std::ostream& file, Droid const& droid)
{
  file << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
  return file;
}
