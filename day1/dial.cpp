#include "dial.h"

Dial::Dial() { pos = 50; }

std::map<std::string, int> Dial::rotateDial(std::string instruction) {
  std::map<std::string, int> result;
  result["clicks"] = 0;

  char dir = instruction[0];
  int steps = std::stoi(instruction.substr(1));

  for (int i = 0; i < steps; i++) {
    if (dir == 'L') {
      pos--;
    } else {
      pos++;
    }

    if (pos < 0)
      pos += 100;
    else if (pos >= 100)
      pos -= 100;

    if (pos == 0)
      result["clicks"]++;
  }

  result["pos"] = pos;

  return result;
}
