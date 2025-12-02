#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

int convertInstruction(std::string instruction) {
  if (instruction[0] == 'L') {
    return -1 * std::stoi(instruction.substr(1));
  }
  return std::stoi(instruction.substr(1));
}

int main(int argc, char *argv[]) {
  std::string filename = argv[1];

  // Open the file and check if valid
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
  }

  int dial = 50;
  int password = 0;

  std::cout << "The dial starts by pointing at " << dial << "." << std::endl;
  std::string line;
  while (std::getline(file, line)) {
    int clicks = convertInstruction(line);
    for (int i = 0; i < std::abs(clicks); i++) {
      if (clicks < 0) {
        dial--;
      } else {
        dial++;
      }
      dial = dial % 100;
      if (dial == 0) {
        password++;
      }
    }
    std::cout << "The dial is rotated " << line << " to point at " << dial
              << "." << std::endl;
  }

  std::cout << "The password is " << password << "." << std::endl;

  return 0;
}
