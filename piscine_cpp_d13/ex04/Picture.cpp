#include	"Picture.h"

//------------Coplien
Picture::Picture() {
  data = ""; }

Picture::Picture(std::string const& file) {
  getPictureFromFile(file); }

Picture::~Picture() {}

Picture&	Picture::operator=(Picture const& pic) {
  data = pic.data;
  return *this;
}

//------------Funcs
bool	Picture::getPictureFromFile(std::string const& file) {
  std::ifstream	fs(file.data());

  if (fs.is_open()) {
    std::stringstream	buffer;
    buffer << fs.rdbuf();
    data = buffer.str();
    fs.close();
    return true;
  }
  data = "ERROR";
  return false;
}
