#include "../include/Matrix.h"
#include <iostream>

int main(void) {
  Matrix<int> hoe = {{2, 2, 0}, {0, 1, 0}, {0, 1, 0}};

  Matrix<int> table = {{1, 0, 1}, {0, 1, 0}, {0, 0, 0}};

  Matrix<int> pick = hoe * table;
  std::cout << "pick = " << std::endl;
  pick.print();


  return 0;
}
