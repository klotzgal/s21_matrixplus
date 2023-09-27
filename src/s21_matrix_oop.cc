#include "s21_matrix_oop.h"

// Конструкторы и деструктор
S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {
  std::cout << "Дефолтный конструктор\n";
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  std::cout << "2 конструктор ";
  if (rows < 0 || cols < 0) {
    throw std::invalid_argument("Invalid matrix");
  } else {
    matrix_ = new double[rows_ * cols_]();
    std::cout << "rows = " << rows_ << ", cols = " << cols_
              << ", matrix = " << matrix_ << "\n";
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_),
      cols_(other.cols_),
      matrix_(new double[rows_ * cols_]()) {
  std::cout << "Конструктор копирования\n";
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  std::cout << "Конструктор перемещения\n";
  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  std::cout << "Деструктор\n";
  Clear();
}

// Операции
double S21Matrix::GetElement(int i, int j) const {
  if (rows_ < i || cols_ < j || i < 0 || j < 0) {
    throw std::invalid_argument("Out of range");
  }
  return (*this)(i, j);
}

void S21Matrix::SetElement(int i, int j, double value) {
  if (rows_ < i || cols_ < j || i < 0 || j < 0) {
    throw std::invalid_argument("Out of range");
  }
  (*this)(i, j) = value;
}

void S21Matrix::PrintMatrix() const {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      std::cout << (*this)(i, j) << " ";
    }
    std::cout << "\n";
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  bool res = true;
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      if ((*this)(i, j) - other(i, j) >= EPS) {
        res = false;
      };
    }
  }
  return res;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Not equal sizes");
  }

  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Not equal sizes");
  }

  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}

// void S21Matrix::MulMatrix(const S21Matrix& other) {
//   if (cols_ != other.rows_) {
//     throw std::invalid_argument("Not valid sizes");
//   }

//   S21Matrix tmp(rows_, other.cols_);
//   for (size_t i = 0; i < tmp.rows_; i++) {
//     for (size_t j = 0; j < tmp.cols_; j++) {
//       for (size_t k = 0; k < cols_; k++) {
//         tmp(i, j) += (*this)(i, k) * other(k, j);
//       }
//     }
//   }
//   Clear();
//   *this = std::move(tmp);
// }

// Перегрузки операторов
double& S21Matrix::operator()(int i, int j) & {
  // std::cout << "\n Оператор(" << i << ", " << j << ")\n";
  return matrix_[i * cols_ + j];
}

double S21Matrix::operator()(int i, int j) const& {
  std::cout << "\nconst Оператор(" << i << ", " << j << ")\n";
  return matrix_[i * cols_ + j];
}

// Вспомогательные приватные методы

void S21Matrix::Clear() {
  rows_ = cols_ = 0;
  if (matrix_) {
    delete[] matrix_;
  }
}