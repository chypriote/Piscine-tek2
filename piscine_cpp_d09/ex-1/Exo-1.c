#include	"Exo-1.h"

//--------------------------------Cthulhu-----------------------------------------//
t_cthulhu	*NewCthulhu()
{
  t_cthulhu	*this = malloc(sizeof(t_cthulhu));
  CthulhuInitializer(this);
  return this;
}

void		CthulhuInitializer(t_cthulhu *this)
{
  this->m_power = 42;
  this->m_name = "Cthulhu";
  printf("----\n");
  printf("Building Cthulhu\n");
}

void		PrintPower(t_cthulhu *this) {
  printf("Power => %i\n", this->m_power); }

void		Attack(t_cthulhu *this)
{
  if (this->m_power >= 42)
    {
      printf("%s attacks and destroys the city\n", this->m_name);
      this->m_power -= 42;
    }
  else
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void		Sleeping(t_cthulhu *this) {
  this->m_power += 42000;
  printf("Cthulhu sleeps\n");
}

//--------------------------------Koala-----------------------------------------//
t_koala		*NewKoala(char *_name, char _isALegend)
{
  t_koala	*this = malloc(sizeof(t_koala));
  KoalaInitializer(this, _name, _isALegend);
  return this;
}

void		KoalaInitializer(t_koala *this, char *_name, char _isALegend)
{
  CthulhuInitializer(&this->m_parent);
  this->m_parent.m_name = _name;
  if (_isALegend)
    this->m_parent.m_power = 42;
  else
    this->m_parent.m_power = 0;
  this->m_isALegend = _isALegend;
  printf("Building %s\n", this->m_parent.m_name);
}

void		Eat(t_koala *this)
{
  this->m_parent.m_power += 42;
  printf("%s eats\n", this->m_parent.m_name);
}
