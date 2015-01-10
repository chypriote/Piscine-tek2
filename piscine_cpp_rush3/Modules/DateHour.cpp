#include	"DateHour.hpp"


DateHour::DateHour(): AModule() {
  _refresh = true;
  _display = new DateHourDisplay();
  _filename = "/proc/driver/rtc";
  fillMap();
}

DateHour::~DateHour() {
  delete _display; }

void	DateHour::fillMap()
{
  std::fstream	file(_filename.c_str(), std::fstream::in);
  std::string	buffer = "";
  std::string	line = "";
  size_t	pos = 0;

  if (file.is_open()) {
    while (getline(file, line))
      buffer += line;
    if ((pos = buffer.find("rtc_time\t:")) != std::string::npos) {
      pos += 11;
      _display->addToMap("Hour", buffer.substr(pos, 8));
    }
    if ((pos = buffer.find("rtc_date\t:", pos)) != std::string::npos) {
      pos += 11;
      _display->addToMap("Date", buffer.substr(pos, 10));
    }
    file.close();
  }
  else
    throw std::string("Couldn't open file : " + _filename);
}
