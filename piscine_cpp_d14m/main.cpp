#include<iostream>
#include"FruitBox.h"
#include"Lemon.h"
#include"Banana.h"
#include"Lime.h"
#include"LittleHand.h"

int     main(void)
{
  FruitBox	vrac(50);
  Mixer		test;

  vrac.putFruit(new Lemon);
  vrac.putFruit(new Banana);
  vrac.putFruit(new Lime);
  vrac.putFruit(new Lemon);
  vrac.putFruit(new Banana);
  vrac.putFruit(new Lime);
  vrac.putFruit(new Lemon);
  vrac.putFruit(new Banana);
  vrac.putFruit(new Lime);
  vrac.putFruit(new Lemon);
  vrac.putFruit(new Banana);
  vrac.putFruit(new Lime);

  LittleHand::plugMixer(test);
  std::cout << test.mix(vrac) << std::endl;
  return (0);
}
