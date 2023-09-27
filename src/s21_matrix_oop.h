
#ifndef _S21_MATRIX_OOP_H_
#define _S21_MATRIX_OOP_H_

#include <algorithm>
#include <iostream>
#include <stdexcept>

#define EPS 1e-7

class S21Matrix {
 private:
  int rows_, cols_;
  double* matrix_;
  // Вспомогательные приватные методы
  void Clear();

 public:
  // Конструкторы и деструктор
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  // Операции
  double GetElement(int i, int j) const;
  void SetElement(int i, int j, double value);
  void PrintMatrix() const;
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  // void MulMatrix(const S21Matrix& other);

  // Перегрузки операторов
  double& operator()(int i, int j) &;
  double operator()(int i, int j) const&;
};

#endif  // _S21_MATRIX_OOP_H_