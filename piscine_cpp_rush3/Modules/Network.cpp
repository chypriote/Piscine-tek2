#include	"Network.hpp"

Network::Network() {
  _refresh = true;
  _filename = "/proc/net/dev";
  _display = new NetworkDisplay;
  for (int i = 0; i < 2; i++)
    _old[i] = 0;
  fillMap();
}

bool	is_digit(char c) {
  return (c >= '0' && c <= '9');
}

void	Network::fillMap() {
  std::fstream	file(_filename.c_str(), std::fstream::in);
  std::string	buffer = "";
  std::string	line = "";
  size_t	pos = 0;
  size_t	end = 0;
  int		_new[2];
  int		i = 0;

  _new[0] = 0;
  _new[1] = 0;
  if (file.is_open()) {
    while (getline(file, line))
      buffer += line;
    if ((pos = buffer.find("wlan0")) != std::string::npos) {
      pos += 7;
      //Recus
      end = buffer.find(" ", pos);
      _new[0] = my_stoi(buffer.substr(pos, end - pos));
      pos = end + 1;
      //Passage aux Transmis
      while (i < 3) {
	pos = buffer.find(" ", pos);
	pos++;
	if (buffer.at(pos) != ' ') {
	  pos = buffer.find(" ", pos);
	  i++;
	}
	pos++;
      }
      //Transmis
      end = buffer.find(" ", pos);
      _new[1] = my_stoi(buffer.substr(pos, end - pos));
    }
    int	montant = _new[1] - _old[1];
    int	desc = _new[0] - _old[0];
    _display->addToMap("Montant", my_itos(montant));
    _display->addToMap("Descendant", my_itos(desc));
    _old[0] = _new[0];
    _old[1] = _new[1];
    file.close();
  }
  else
    throw std::string("Couldn't open file : " + _filename);
}
