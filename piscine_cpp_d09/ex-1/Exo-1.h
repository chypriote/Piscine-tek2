#ifndef		EXO_1_H_
#define		EXO_1_H_

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

typedef	struct	s_cthulhu
{
  int		m_power;
  char		*m_name;
}		t_cthulhu;

typedef	struct	s_koala
{
  t_cthulhu	m_parent;
  char		m_isALegend;
}		t_koala;


t_cthulhu	*NewCthulhu();
void		PrintPower(t_cthulhu *);
void		Attack(t_cthulhu *);
void		Sleeping(t_cthulhu *);
t_koala		*NewKoala(char *, char);
void		Eat(t_koala *);

static void	KoalaInitializer(t_koala *, char *, char);
static void	CthulhuInitializer(t_cthulhu *);

#endif
