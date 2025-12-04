#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool inBounds(std::vector<std::vector<char>> &grid, int row, int col) {
  if (row < 0 || row >= grid.size()) {
    return false;
  }
  if (col < 0 || col >= grid[0].size()) {
    return false;
  }
  return true;
}

bool isValidPosition(std::vector<std::vector<char>> &grid, int row, int col) {
  std::vector<int> h_offsets = {-1, 0, 1}; // left, same, right
  std::vector<int> v_offsets = {-1, 0, 1}; // up, same, down

  int neighbors = 0;

  for (int dh = 0; dh < h_offsets.size(); dh++) {
    for (int dv = 0; dv < v_offsets.size(); dv++) {

      // Skip checking itself
      if (h_offsets[dh] == 0 && v_offsets[dv] == 0)
        continue;

      int new_row = row + v_offsets[dv];
      int new_col = col + h_offsets[dh];

      if (!inBounds(grid, new_row, new_col))
        continue;

      if (grid[new_row][new_col] == '@')
        neighbors++;
    }
  }

  return neighbors < 4;
}

int main(int argc, char *argv[]) {
  std::string filename = argv[1];

  // Open the file and check if valid
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
  }

  std::vector<std::vector<char>> grid;

  // Load the file into a grid
  std::string line;
  while (std::getline(file, line)) {
    std::vector<char> characters;
    for (int i = 0; i < line.size(); i++) {
      characters.push_back(line[i]);
    }
    grid.push_back(characters);
  }

  int password = 0;
  int rolls_removed = -1;

  // Loop through each possible iteration
  while (rolls_removed != 0) {
    std::vector<std::vector<char>> new_grid = grid;
    rolls_removed = 0;

    // Loop through each position in the grid
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == '@' && isValidPosition(grid, row, col)) {
          rolls_removed++;
          new_grid[row][col] = '.';
        }
      }
    }

    password += rolls_removed;
    grid = new_grid;

    std::cout << rolls_removed << " rolls were removed." << std::endl;
  }

  std::cout << "The password is " << password << std::endl;

  return 0;
}
