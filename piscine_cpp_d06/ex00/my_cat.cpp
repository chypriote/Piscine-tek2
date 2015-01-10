#include	<string>
#include	<fstream>
#include	<iostream>


int		main(int ac, char **av)
{
  int		i = 1;
  std::fstream	file;

  if (ac == 1)
    std::cout << "my_cat: Usage : ./my_cat file [...]" << std::endl;
  while (i < ac)
    {
      file.open(av[i], std::iostream::in);
      if (file)
	{
	  int	n;
	  char	str[255];
	  while (n = file.readsome(str, 255))
	    std::cout.write(str, n);
	  file.close();
	}
      else
	std::cerr << "my_cat : " << av[i] << ": No such file or directory" << std::endl;
      i++;
    }
}
