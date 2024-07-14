#include "../include/Matrix.h"
#include "../include/Vector.h"

int main() {
  // Vector test
  Vector v1(3);
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 34.0;
  std::cout << "v2 = " << std::endl;
  v1.print();
  std::cout << "\n" << std::endl;

  std::vector<double> elems = {4.0, 5.0, 6.0};
  Vector v2(elems);
  std::cout << "v2 = " << std::endl;
  v2.print();
  std::cout << "\n" << std::endl;

  // Matrix test
  Matrix m1(2, 3);
  m1[0][0] = 1.0;
  m1[0][1] = 2.0;
  m1[0][2] = 3.0;
  m1[1][0] = 4.0;
  m1[1][1] = 5.0;
  m1[1][2] = 6.0;

  std::cout << "m1 = " << std::endl;
  m1.print();
  std::cout << "\n" << std::endl;

  std::vector<std::vector<double>> matrixElems = {{7.0, 8.0, 9.0},
                                                  {10.0, 11.0, 12.0}};
  Matrix m2(matrixElems);

  std::cout << "m2 = " << std::endl;
  m2.print();
  std::cout << "\n" << std::endl;

  return 0;
}

