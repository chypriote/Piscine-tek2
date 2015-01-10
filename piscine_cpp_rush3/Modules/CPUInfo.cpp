#include	"CPUInfo.hpp"

CPUInfo::CPUInfo() {
  _refresh = true;
  _filename = "/proc/cpuinfo";
  _filename2 = "/proc/stat";
  _display = new CPUInfoDisplay;
  for (int i = 0; i < 2; i++)
    _cpu0[i] = 0;
  for (int i = 0; i < 2; i++)
    _cpu1[i] = 0;
  for (int i = 0; i < 2; i++)
    _cpu2[i] = 0;
  for (int i = 0; i < 2; i++)
    _cpu3[i] = 0;
  fillMap();
}

void	CPUInfo::fillMap() {
  std::fstream	file(_filename.c_str(), std::fstream::in);
  std::string	buffer = "";
  std::string	line = "";
  size_t	pos = 0;
  size_t	end = 0;

  if (file.is_open()) {
    while (getline(file, line))
      buffer += line;
    if ((pos = buffer.find("model name")) != std::string::npos) {
      pos += 13;
      end = buffer.find("stepping", pos);
      _display->addToMap("ModelName", buffer.substr(pos, end - pos));
    }
    file.close();
  }
  else
    throw std::string("Couldn't open file : " + _filename);
  getCPUCharge();
}

void	CPUInfo::getCPUCharge() {
  std::fstream	file(_filename2.c_str(), std::fstream::in);
  std::string	buffer = "";
  std::string	line = "";
  size_t	pos = 0;

  if (file.is_open()) {
    while (getline(file, line))
      buffer += line;

    pos = refreshValues(buffer, pos, _cpu0, "Cpu0");
    pos = refreshValues(buffer, pos, _cpu1, "Cpu1");
    pos = refreshValues(buffer, pos, _cpu2, "Cpu2");
    pos = refreshValues(buffer, pos, _cpu3, "Cpu3");
    file.close();
  }
}

int	CPUInfo::refreshValues(std::string buffer, size_t pos, int *_cpu, std::string name) {
  size_t	end;
  int	_new[2];

  _new[0] = 0;
  _new[1] = 0;

  if ((pos = buffer.find("cpu", pos)) != std::string::npos) {
    pos += 5;    
    for (int i = 0; i < 8; i++) {
      end = buffer.find(" ", pos);      
      _new[1] += my_stoi(buffer.substr(pos, end - pos));      
      if (i == 2)
	_new[0] = _new[1];
      pos = end + 1;
    }
  }
  if (_new[1] - _cpu[1] != 0) {
    int	usage = ((_new[0] - _cpu[0]) * 100) / (_new[1] - _cpu[1]);
    _display->addToMap(name, my_itos(usage));
  }
  _cpu[0] = _new[0];
  _cpu[1] = _new[1];
  return pos;
}
