#include        "OSKernel.hpp"


OSKernel::OSKernel(): AModule()
{
  _refresh = true;
  _display = new OSKernelDisplay();
  _filename = "/proc/sys/kernel/osrelease";
  _filename2 = "/etc/os-release";
  fillMap();
}

OSKernel::~OSKernel() {
  delete _display; }

void    OSKernel::fillMap()
{
  std::fstream  file(_filename.c_str(), std::fstream::in);
  std::fstream  file2(_filename2.c_str(), std::fstream::in);
  std::string   buffer = "";
  std::string   line = "";
  size_t        pos = 0;
  size_t        end = 0;

  if (file2.is_open()) {
    while (getline(file2, line))
      buffer += line;
    if ((pos = buffer.find("_NAME=\"", pos)) != std::string::npos) {
      pos += 7;
      end = buffer.find("\"", pos);
      _display->addToMap("Operating System", buffer.substr(pos, end - pos));
    }
  }
  else
    throw std::string("Couldn't open file : " + _filename2);

  buffer = "";
  line = "";
  if (file.is_open()) {
    while (getline(file, line))
      buffer += line;
    _display->addToMap("Kernel", buffer);
  }
  else
    throw std::string("Couldn't open file : " + _filename);
}

