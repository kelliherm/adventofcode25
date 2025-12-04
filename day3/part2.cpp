#include <fstream>
#include <iostream>
#include <string>

long long getLargestNumber(std::string line) {
  std::string result;
  int n = line.size();
  int max_index = -1;

  for (int digit = 0; digit < 12; digit++) {
    int high = -1;
    int index = -1;

    for (int loc = max_index + 1; loc < n - 12 + digit + 1; loc++) {
      int num = line[loc] - '0';
      if (num > high) {
        high = num;
        index = loc;
      }
    }

    result.push_back('0' + high);
    max_index = index;
  }

  return std::stoll(result);
}

int main(int argc, char *argv[]) {
  std::string filename = argv[1];

  // Open the file and check if valid
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
  }

  long long password = 0;

  // Parse through each line
  std::string line;
  while (std::getline(file, line)) {
    long long result = getLargestNumber(line);
    std::cout << result << " is the largest number found in " << line
              << std::endl;
    password += result;
  }

  std::cout << "The password is " << password << "." << std::endl;

  return 0;
}
