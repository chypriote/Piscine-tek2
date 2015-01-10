#include	"UserInfo.hpp"


UserInfo::UserInfo(): AModule() 
{
  _refresh = true;
  _display = new UserInfoDisplay();
  _filename = "/proc/self/environ";
  fillMap();
}

UserInfo::~UserInfo() {
  delete _display; }

void	UserInfo::fillMap()
{
  std::fstream	file(_filename.c_str(), std::fstream::in);
  std::string	buffer = "";
  std::string	line = "";
  size_t	pos = 0;
  size_t	end = 0;

  if (file.is_open()) {
    while (getline(file, line))
      buffer += line;
    if ((pos = buffer.find("USER=")) != std::string::npos) {
      pos += 5;
      end = buffer.find("GROUP", pos);
      _display->addToMap("Username", buffer.substr(pos, end - pos));
    }
    if ((pos = buffer.find("HOST=")) != std::string::npos) {
      pos += 5;
      end = buffer.find("WINDOW_MANAGER", pos);
      _display->addToMap("Machine name", buffer.substr(pos, end - pos));
    }
    file.close();
  }
  else
    throw std::string("Couldn't open file : " + _filename);
}
