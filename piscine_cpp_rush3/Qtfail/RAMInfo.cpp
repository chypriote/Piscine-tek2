#include        "RAMInfo.hpp"

RAMInfo::RAMInfo(): AModule() {
  _refresh = true;
  _display = new RAMInfoDisplay();
  _filename = "/proc/meminfo";
  fillMap();
}

RAMInfo::~RAMInfo() {
  delete _display; }

void    RAMInfo::fillMap()
{
  std::fstream  file(_filename.c_str(), std::fstream::in);
  std::string   buffer = "";
  std::string   line = "";
  size_t        pos = 0;
  int           total = 0;
  int           free = 0;
  int           used = 0;

  if (file.is_open()) {
    while (getline(file, line))
      buffer += line;
    if ((pos = buffer.find("MemTotal")) != std::string::npos) {
      std::istringstream a(buffer.substr(pos + 10, std::string::npos));
      a >> total;
    }
    if ((pos = buffer.find("MemFree")) != std::string::npos) {
      std::istringstream b(buffer.substr(pos + 9, std::string::npos));
      b >> free;
    }

    std::ostringstream a;
    a << total;
    std::string tmp(a.str());
    _display->addToMap("Total", tmp);

    a.str("");
    a << free;
    tmp = a.str();
    _display->addToMap("Free", tmp);

    used = 100 - (free * 100 / total);
    a.str("");
    a << used;
    tmp = a.str();
    _display->addToMap("Usage", tmp);
    file.close();
   }
   else
     throw std::string("Couldn't open file : " + _filename);
 }
