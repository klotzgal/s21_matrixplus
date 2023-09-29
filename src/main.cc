#include "s21_matrix_oop.h"

int main() {
  // m.PrintMatrix();
  // // S21Matrix mov(std::move(m));
  const S21Matrix m2{5,  5, 1, 4, 2, 5, 3, 6, 2, 9, 8, 11, 1, 1,
               12, 1, 1, 4, 4, 4, 4, 4, 1, 2, 3, 4,  5};
  // // m2.PrintMatrix();
  // m2.PrintMatrix();
  // S21Matrix m = m2;
  // m.InverseMatrix();
  // m.PrintMatrix();
  // m.MulMatrix(m2);
  // m.PrintMatrix();
  double det = m2.Determinant();
  std::cout << "det = " << det << "\n";
  // // m.MulMatrix(m2);
  // m.Transpose();
  // m.PrintMatrix();

  return 0;
}
