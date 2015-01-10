#include	"droid.hh"

//------------------------------------Droid---------------------------------//
Droid::Droid(std::string serial) : Id(serial), Energy(50), Attack(25), Toughness(15)
{
  Status = new std::string("Standing by");
  BattleData = new DroidMemory();
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

//-----------------------------------Droid: getters-------------------------------//
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

DroidMemory	*Droid::getBattleData() const {
  return BattleData; }

//----------------------------------Droid: setters--------------------------------//
void		Droid::setId(std::string id) {
  Id = id; }

void		Droid::setEnergy(size_t nrg) {
  Energy = nrg; }

void		Droid::setStatus(std::string *stat) {
  Status = stat; }

void		Droid::setBattleData(DroidMemory *data)
{
  delete BattleData;
  BattleData = data;
}

//----------------------------------Droid: operators---------------------------//
bool		Droid::operator==(Droid const &droid) const {
  return (*Status == *droid.Status); }

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
      int take = std::min(100 - Energy, nrg);
      Energy += take;
      nrg -= take;
    }
  return *this;
}

bool		Droid::operator()(std::string const *task, size_t xp)
{
  if (Energy <= 10)
    {
      Energy = 0;
      setStatus(new std::string("Battery Low"));
      return false;
    }
  Energy -= 10;
  std::string	*tmp = new std::string(*task);
  if (*BattleData < xp)
    {
      *tmp += " - Completed!";
      setStatus(tmp);
      BattleData->setExp(BattleData->getExp() + (xp / 2));
      return true;
    }
  else
    {
      *tmp += " - Failed!";
      setStatus(tmp);
      BattleData->setExp(BattleData->getExp() + xp);
      return false;
    }
}

std::ostream&	operator<<(std::ostream& file, Droid const& droid)
{
  file << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
  return file;
}
