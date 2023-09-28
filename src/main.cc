#include "s21_matrix_oop.h"

int main() {
  S21Matrix m{4, 4, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  m.PrintMatrix();
  // S21Matrix mov(std::move(m));
  S21Matrix m2(4 * m * 0.5);
  m2.PrintMatrix();

  return 0;
}
