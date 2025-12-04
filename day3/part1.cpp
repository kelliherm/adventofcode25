#include <fstream>
#include <iostream>
#include <string>

int getLargestNumber(std::string line) {
  int max = 0;
  for (int i = 0; i < (line.size() - 1); i++) {
    for (int j = i + 1; j < line.size(); j++) {
      std::string s;
      s.push_back(line[i]);
      s.push_back(line[j]);
      int num = std::stoi(s);
      if (num > max) {
        max = num;
      }
    }
  }
  return max;
}

int main(int argc, char *argv[]) {
  std::string filename = argv[1];

  // Open the file and check if valid
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
  }

  int password = 0;

  // Parse through each line
  std::string line;
  while (std::getline(file, line)) {
    int result = getLargestNumber(line);
    std::cout << result << " is the largest number found in " << line
              << std::endl;
    password += result;
  }

  std::cout << "The password is " << password << "." << std::endl;

  return 0;
}
