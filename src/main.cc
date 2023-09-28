#include "s21_matrix_oop.h"

int main() {
  S21Matrix m{3, 2, 1, 4, 2, 5, 3, 6};
  m.PrintMatrix();
  // S21Matrix mov(std::move(m));
  S21Matrix m2{2, 3, 1, -1, 1, 2, 3, 4};
  m2.PrintMatrix();

  m2.MulMatrix(m);
  m2.PrintMatrix();

  return 0;
}
