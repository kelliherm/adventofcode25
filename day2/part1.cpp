#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string &s, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::stringstream ss(s); // Create a stringstream from the input string

  // Read tokens from the stringstream until the delimiter is found
  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

int main(int argc, char *argv[]) {
  std::string filename = argv[1];

  // Open the file and check if valid
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
  }

  // Get the ranges from the file
  std::string input;
  std::getline(file, input);
  std::vector<std::string> ranges = splitString(input, ',');

  long long password = 0;

  for (int i = 0; i < ranges.size(); i++) {
    std::string range = ranges[i];
    std::vector<std::string> limits = splitString(range, '-');
    long long lower = std::stoll(limits[0]);
    long long upper = std::stoll(limits[1]);

    for (long long j = lower; j <= upper; j++) {
      std::string s = std::to_string(j);
      if (s.size() % 2 == 0) {
        if (s.substr(0, s.size() / 2) == s.substr(s.size() / 2)) {
          std::cout << "While searching in the range of " << lower << "-"
                    << upper << " the invalid code of " << s << " was found."
                    << std::endl;
          password += j;
        }
      }
    }
  }

  std::cout << "The password is " << password << "." << std::endl;

  return 0;
}
