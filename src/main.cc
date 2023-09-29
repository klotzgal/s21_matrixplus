#include "s21_matrix_oop.h"

int main() {
  S21Matrix m;
  // m.PrintMatrix();
  // // S21Matrix mov(std::move(m));
  S21Matrix m2{3, 3, 2, 3, -1, 2, 3, 4, 1, 1, 1};
  // // m2.PrintMatrix();
  m2.PrintMatrix();
  double det = m2.Determinant();
  std::cout << "det = " << det << "\n";
  // // m.MulMatrix(m2);
  // m.Transpose();
  // m.PrintMatrix();

  return 0;
}
