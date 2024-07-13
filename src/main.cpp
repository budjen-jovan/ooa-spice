#include "../include/Matrix.h"
#include <iostream>

int main(void) {
  Matrix<int> hoe = {{2, 2, 0}, {0, 1, 0}, {0, 1, 0}};
  Matrix<int> table = {{1, 0, 1}, {0, 1, 0}, {0, 0, 0}};

  Matrix<int> pick = hoe * table;
  std::cout << "pick = " << std::endl;
  pick.print();

  auto v1 = Vector<int>{1, 2, 3};
  auto v2 = Vector<int>{5, 5, 5};

  std::cout << "v1 = " << std::endl;
  v1.print();

  std::cout << "v2 = " << std::endl;
  v2.print();

  auto v3 = v1 * v2;
  std::cout << "<v1, v2> = " << v3 << std::endl;

  auto v4 = v1 + v2;
  std::cout << "v1 + v2 = " << std::endl;
  v4.print();
  
  auto m1 = Matrix<int>::eye(3);
  std::cout << "m1 = " << std::endl;
  m1.print();
  
  auto m2 = Matrix<double>::zeros(4, 6);
  std::cout << "m2 = " << std::endl;
  m2.print();

  auto m3 = Matrix<int>::ones(2, 4);
  m3 = m3 * 3;
  std::cout << "m3 = " << std::endl;
  m3.print();

  return 0;
}
