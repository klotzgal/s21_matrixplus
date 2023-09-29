
#ifndef _S21_MATRIX_OOP_H_
#define _S21_MATRIX_OOP_H_

#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

#define EPS 1e-7

class S21Matrix {
 private:
  int rows_, cols_;
  double* matrix_;
  // Вспомогательные приватные методы
  void Clear();
  double SimpleDet();
  double Minor(int n, int m);
  double Complement(int n, int m);

 public:
  // Конструкторы и деструктор
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(std::initializer_list<double> init);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  //  Геттеры и сеттеры
  // double GetElement(int i, int j) const;
  // void SetElement(int i, int j, double value);
  double GetRow() const;
  void SetRow(int row);
  double GetColumn() const;
  void SetColumn(int column);

  // Операции
  void PrintMatrix() const;
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();

  // Перегрузки операторов
  double& operator()(int i, int j);
  double operator()(int i, int j) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  friend S21Matrix operator*(double num, const S21Matrix& other);
  bool operator==(const S21Matrix& other) const noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  // S21Matrix& operator+=(S21Matrix&& other);
};

#endif  // _S21_MATRIX_OOP_H_