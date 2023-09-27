#include "s21_matrix_oop.h"

int main() {
  std::cout << "Matrix"
            << "\n";
  S21Matrix m(5, 4);
  m.SetElement(1, 1, 4);
  m.SetElement(2, 3, 2);
  S21Matrix m2(4, 1);
  // m.MulMatrix(m2);
  // std::cout << "getElement = " << m(1, 1) << "\n";
  // std::cout << "Eq = " <<  m.EqMatrix(m2) << "\n";
  // int a = 5;
  // const int& s = 1;
  // int&& s2 = 4;
  // std::cout << "a = " << a << ", s = " << s << ", s2 = " << s2 << "\n";
  return 0;
}
