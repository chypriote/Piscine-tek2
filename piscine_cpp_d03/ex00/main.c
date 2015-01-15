#include	"String.h"

int		main(void)
{
  String	lapin;

  StringInit(&lapin, "coucou");
  StringDestroy(&lapin);
  return 0;
}
