#include	<string>
#include	<stdlib.h>
#include	<stdio.h>
#include	<iostream>
#include	<iomanip>

int		main()
{
  float		temp;
  float		newtemp;
  std::string	unite;

  std::cin >> temp >> unite;
  if (!unite.compare("Fahrenheit"))
    {
      newtemp = 5.000 / 9.0 * (temp - 32);
      std::cout << std::setw(16) << std::fixed << std::setprecision(3) << newtemp;
      std::cout << std::setw(16) << "Celsius" << std::endl;
    }
  else if (!unite.compare("Celsius"))
    {
      newtemp = temp * 9.000 / 5 + 32;
      std::cout << std::setw(16) << std::fixed << std::setprecision(3) << newtemp;
      std::cout << std::setw(16) << "Fahrenheit" << std::endl;
    }
  return 0;
}
