#include	"RAMInfo.hpp"

RAMInfo::RAMInfo(): AModule() {
  _refresh = true;
  _display = new RAMInfoDisplay();
  _filename = "/proc/meminfo";
  fillMap();
}

RAMInfo::~RAMInfo() {
  delete _display; }

void	RAMInfo::fillMap()
{
  std::fstream	file(_filename.c_str(), std::fstream::in);
  std::string	buffer = "";
  std::string	line = "";
  size_t	pos = 0;
  int		total = 0;
  int		free = 0;
  int		used = 0;

  if (file.is_open()) {
    while (getline(file, line))
      buffer += line;
    if ((pos = buffer.find("MemTotal")) != std::string::npos)
      total = my_stoi(buffer.substr(pos + 10, std::string::npos));
    if ((pos = buffer.find("MemFree")) != std::string::npos)
      free = my_stoi(buffer.substr(pos + 9, std::string::npos));

    _display->addToMap("Total", my_itos(total));
    _display->addToMap("Free", my_itos(free));
    used = 100 - (free * 100 / total);
    _display->addToMap("Usage", my_itos(used));
    file.close();
  }
  else
    throw std::string("Couldn't open file : " + _filename);
}
