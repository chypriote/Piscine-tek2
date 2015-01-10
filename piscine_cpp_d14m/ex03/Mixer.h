#ifndef		MIXER_H_
#define		MIXER_H_

#include	"MixerBase.h"

class	Mixer : public MixerBase {
 public:
  Mixer();
  virtual ~Mixer();

  void		plugIN();
};

int		mixage(FruitBox&);

#endif
