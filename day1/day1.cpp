#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "dial.h"

int main(int argc, char *argv[]) {
  std::string filename = argv[1];
  std::string part = argv[2];

  Dial dial;
  int password = 0;

  // Open the file and check if valid
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 0;
  }

  std::cout << "The dial starts by pointing at 50." << std::endl;
  std::string instruction;
  while (std::getline(file, instruction)) {
    std::map<std::string, int> result = dial.rotateDial(instruction);
    if (part == "p1") {
      if (result["pos"] == 0) {
        password++;
      }
      std::cout << "The dial is rotated " << instruction << " to point at "
                << result["pos"] << "." << std::endl;
    }
    if (part == "p2") {
      password += result["clicks"];
      std::cout << "The dial is rotated " << instruction << " to point at "
                << result["pos"]
                << "; during this rotation, it points at 0 a total of "
                << result["clicks"] << " times." << std::endl;
    }
  }

  std::cout << "The password is " << password << "." << std::endl;

  return 0;
}
