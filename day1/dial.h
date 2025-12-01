#include <map>
#include <string>

#ifndef DIAL_H
#define DIAL_H

class Dial {
public:
  Dial();
  std::map<std::string, int> rotateDial(std::string rotation);

private:
  int pos;
};

#endif
