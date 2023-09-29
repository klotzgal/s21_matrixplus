#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

//*
class MatrixTests : public testing::Test {
 protected:
  S21Matrix *m1x1;
  S21Matrix *m3x3;
  S21Matrix *m1x5;
  S21Matrix *m5x1;
  S21Matrix *m2x3;
  S21Matrix *m3x2;
  S21Matrix *m5x5;

  void SetUp() {
    m1x1 = new S21Matrix{1, 1, 5};
    m3x3 = new S21Matrix{3, 3, 2, 4, 6, 7, 5, 3, 8, 9, 1};
    m1x5 = new S21Matrix{1, 5, 1, 2, 3, 4, 5};
    m5x1 = new S21Matrix{5, 1, 4, 7, 5, 6, 8};
    m2x3 = new S21Matrix{2, 3, 1, -1, 1, 2, 3, 4};
    m3x2 = new S21Matrix{3, 2, 1, 4, 2, 5, 3, 6};
    m5x5 = new S21Matrix{5,  5, 1, 4, 2, 5, 3, 6, 2, 9, 8, 11, 1, 1,
                         12, 1, 1, 4, 4, 4, 4, 4, 1, 2, 3, 4,  5};
  }
  void TearDown() {
    delete m1x1;
    delete m3x3;
    delete m1x5;
    delete m5x1;
    delete m2x3;
    delete m3x2;
    delete m5x5;
    m1x1 = m3x3 = m1x5 = m5x1 = m3x2 = m2x3 = m5x5 = nullptr;
  }
};

//* Constructors
TEST(ConstructorsTestGroup, Test_1) { ASSERT_NO_THROW(S21Matrix m(1, 1)); }
TEST(ConstructorsTestGroup, Test_2) { ASSERT_ANY_THROW(S21Matrix m(0, 0)); }
TEST(ConstructorsTestGroup, Test_3) { ASSERT_ANY_THROW(S21Matrix m(5, 0)); }
TEST(ConstructorsTestGroup, Test_4) { ASSERT_ANY_THROW(S21Matrix m(-1, 1)); }
TEST(ConstructorsTestGroup, Test_5) { ASSERT_ANY_THROW(S21Matrix m(1, -0)); }
TEST(ConstructorsTestGroup, Test_6) { ASSERT_NO_THROW(S21Matrix m(5, 5)); }
TEST(ConstructorsTestGroup, Test_7) { ASSERT_ANY_THROW(S21Matrix m(1, -1)); }
TEST(ConstructorsTestGroup, Test_8) { ASSERT_NO_THROW(S21Matrix m); }

//* Copy constructor
TEST_F(MatrixTests, CopyTest_1) {
  S21Matrix m(*m1x1);
  ASSERT_EQ(m.EqMatrix(*m1x1), true);
}

TEST_F(MatrixTests, CopyTest_2) {
  S21Matrix m(*m3x3);
  ASSERT_EQ(m.EqMatrix(*m3x3), true);
}

TEST_F(MatrixTests, CopyTest_3) {
  S21Matrix m(*m1x5);
  ASSERT_EQ(m.EqMatrix(*m1x5), true);
}

TEST_F(MatrixTests, CopyTest_4) {
  S21Matrix m(*m5x1);
  ASSERT_EQ(m.EqMatrix(*m5x1), true);
}

//* Move constructor
TEST_F(MatrixTests, MoveTest_1) {
  S21Matrix m1(*m3x3);
  S21Matrix m2(std::move(m1));

  ASSERT_EQ(m2.EqMatrix(*m3x3), true);
  ASSERT_EQ(m1.GetCols(), 0);
  ASSERT_EQ(m1.GetRows(), 0);
}

TEST_F(MatrixTests, MoveTest_2) {
  S21Matrix m1(*m3x3);
  S21Matrix m2(std::move(m1));

  ASSERT_EQ(m2.EqMatrix(*m3x3), true);
  ASSERT_EQ(m1.GetCols(), 0);
  ASSERT_EQ(m1.GetRows(), 0);
}

TEST_F(MatrixTests, MoveTest_3) {
  S21Matrix m1(*m1x5);
  S21Matrix m2(std::move(m1));

  ASSERT_EQ(m2.EqMatrix(*m1x5), true);
  ASSERT_EQ(m1.GetCols(), 0);
  ASSERT_EQ(m1.GetRows(), 0);
}

TEST_F(MatrixTests, MoveTest_4) {
  S21Matrix m1(*m5x1);
  S21Matrix m2(std::move(m1));

  ASSERT_EQ(m2.EqMatrix(*m5x1), true);
  ASSERT_EQ(m1.GetCols(), 0);
  ASSERT_EQ(m1.GetRows(), 0);
}

//* Getters
TEST_F(MatrixTests, GetTest_1) {
  ASSERT_EQ(m1x1->GetRows(), 1);
  ASSERT_EQ(m1x1->GetCols(), 1);
}

TEST_F(MatrixTests, GetTest_2) {
  ASSERT_EQ(m3x3->GetRows(), 3);
  ASSERT_EQ(m2x3->GetCols(), 3);
}

//* Setters
TEST_F(MatrixTests, SetTest_1) {
  m1x1->SetRows(3);
  ASSERT_EQ(m1x1->GetRows(), 3);
  m1x1->SetCols(4);
  ASSERT_EQ(m1x1->GetCols(), 4);
}

TEST_F(MatrixTests, SetTest_2) { ASSERT_ANY_THROW(m1x1->SetRows(-1)); }

TEST_F(MatrixTests, SetTest_3) { ASSERT_ANY_THROW(m1x1->SetCols(-1)); }

//* EqualMatrix
TEST_F(MatrixTests, EqTest_1) {
  S21Matrix m1{3, 3, 2, 4, 6, 7, 5, 3, 8, 9, 1};
  ASSERT_EQ(m1.EqMatrix(*m3x3), true);
}

TEST_F(MatrixTests, EqTest_3) {
  S21Matrix m1{3, 3, 2, 4, 6, 7, 5, 3, 8, 9, 1};
  ASSERT_EQ(m1.EqMatrix(*m1x1), false);
}

TEST_F(MatrixTests, EqTest_4) {
  S21Matrix m1;
  ASSERT_EQ(m1.EqMatrix(*m1x5), false);
}

TEST_F(MatrixTests, EqTest_5) {
  S21Matrix m1;
  m1(0, 0) = 5;
  ASSERT_EQ(m1.EqMatrix(*m1x1), true);
}

TEST_F(MatrixTests, EqTest_6) {
  S21Matrix m1{3, 3, 2, -4, 6, 7, 5, 3, 8, 9, 1};
  ASSERT_EQ(m1.EqMatrix(*m3x3), false);
}

//* Sum Matrix
TEST_F(MatrixTests, SumTest_1) {
  S21Matrix m1{3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  m1.SumMatrix(*m3x3);
  ASSERT_EQ(m1(0, 0), 3);
  ASSERT_EQ(m1(0, 1), 5);
  ASSERT_EQ(m1(0, 2), 7);
  ASSERT_EQ(m1(1, 0), 8);
  ASSERT_EQ(m1(1, 1), 6);
  ASSERT_EQ(m1(1, 2), 4);
  ASSERT_EQ(m1(2, 0), 9);
  ASSERT_EQ(m1(2, 1), 10);
  ASSERT_EQ(m1(2, 2), 2);
}

TEST_F(MatrixTests, SumTest_2) {
  S21Matrix m1{3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_ANY_THROW(m1.SumMatrix(*m1x1));
}

TEST_F(MatrixTests, SumTest_3) { ASSERT_ANY_THROW(m1x5->SumMatrix(*m5x1)); }

TEST_F(MatrixTests, SumTest_4) { ASSERT_ANY_THROW(m1x1->SumMatrix(*m5x1)); }

//* Sub Matrix
TEST_F(MatrixTests, SubTest_1) {
  S21Matrix m1{3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  m1.SubMatrix(*m3x3);
  ASSERT_EQ(m1(0, 0), -1);
  ASSERT_EQ(m1(0, 1), -3);
  ASSERT_EQ(m1(0, 2), -5);
  ASSERT_EQ(m1(1, 0), -6);
  ASSERT_EQ(m1(1, 1), -4);
  ASSERT_EQ(m1(1, 2), -2);
  ASSERT_EQ(m1(2, 0), -7);
  ASSERT_EQ(m1(2, 1), -8);
  ASSERT_EQ(m1(2, 2), 0);
}

TEST_F(MatrixTests, SubTest_2) {
  S21Matrix m1{3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_ANY_THROW(m1.SubMatrix(*m1x1));
}

TEST_F(MatrixTests, SubTest_3) { ASSERT_ANY_THROW(m1x5->SubMatrix(*m5x1)); }

TEST_F(MatrixTests, SubTest_4) { ASSERT_ANY_THROW(m3x3->SubMatrix(*m5x1)); }

//* Mul Number
TEST_F(MatrixTests, MulNumTest_1) {
  m1x1->MulNumber(2);
  ASSERT_EQ((*m1x1)(0, 0), 10);
}

TEST_F(MatrixTests, MulNumTest_2) {
  m1x1->MulNumber(0.5);
  ASSERT_EQ((*m1x1)(0, 0), 2.5);
}

TEST_F(MatrixTests, MulNumTest_3) {
  m1x1->MulNumber(-2);
  ASSERT_EQ((*m1x1)(0, 0), -10);
}

TEST_F(MatrixTests, MulNumTest_4) {
  m3x3->MulNumber(5);
  ASSERT_EQ((*m3x3)(0, 0), 10);
  ASSERT_EQ((*m3x3)(0, 1), 20);
  ASSERT_EQ((*m3x3)(0, 2), 30);
  ASSERT_EQ((*m3x3)(1, 0), 35);
  ASSERT_EQ((*m3x3)(1, 1), 25);
  ASSERT_EQ((*m3x3)(1, 2), 15);
  ASSERT_EQ((*m3x3)(2, 0), 40);
  ASSERT_EQ((*m3x3)(2, 1), 45);
  ASSERT_EQ((*m3x3)(2, 2), 5);
}

//* Mul Matrix
TEST_F(MatrixTests, MulMatrixTest_1) {
  m3x2->MulMatrix(*m2x3);
  ASSERT_EQ((*m3x2)(0, 0), 9);
  ASSERT_EQ((*m3x2)(0, 1), 11);
  ASSERT_EQ((*m3x2)(0, 2), 17);
  ASSERT_EQ((*m3x2)(1, 0), 12);
  ASSERT_EQ((*m3x2)(1, 1), 13);
  ASSERT_EQ((*m3x2)(1, 2), 22);
  ASSERT_EQ((*m3x2)(2, 0), 15);
  ASSERT_EQ((*m3x2)(2, 1), 15);
  ASSERT_EQ((*m3x2)(2, 2), 27);
}

TEST_F(MatrixTests, MulMatrixTest_2) {
  m2x3->MulMatrix(*m3x3);
  ASSERT_EQ((*m2x3)(0, 0), 3);
  ASSERT_EQ((*m2x3)(0, 1), 8);
  ASSERT_EQ((*m2x3)(0, 2), 4);
  ASSERT_EQ((*m2x3)(1, 0), 57);
  ASSERT_EQ((*m2x3)(1, 1), 59);
  ASSERT_EQ((*m2x3)(1, 2), 25);
}

TEST_F(MatrixTests, MulMatrixTest_3) {
  ASSERT_ANY_THROW(m2x3->MulMatrix(*m1x1));
}

//* Transpose Matrix
TEST_F(MatrixTests, TransposeTest_1) {
  m1x5->Transpose();
  ASSERT_EQ(m1x5->GetRows(), 5);
  ASSERT_EQ(m1x5->GetCols(), 1);
  ASSERT_EQ((*m1x5)(0, 0), 1);
  ASSERT_EQ((*m1x5)(1, 0), 2);
  ASSERT_EQ((*m1x5)(2, 0), 3);
  ASSERT_EQ((*m1x5)(3, 0), 4);
  ASSERT_EQ((*m1x5)(4, 0), 5);
}

TEST_F(MatrixTests, TransposeTest_2) {
  m1x1->Transpose();
  ASSERT_EQ(m1x1->GetRows(), 1);
  ASSERT_EQ(m1x1->GetCols(), 1);
  ASSERT_EQ((*m1x1)(0, 0), 5);
}

//* CalcComplements
TEST_F(MatrixTests, CalcComplementsTest_1) {
  m3x3->CalcComplements();
  ASSERT_EQ((*m3x3)(0, 0), -22);
  ASSERT_EQ((*m3x3)(0, 1), 17);
  ASSERT_EQ((*m3x3)(0, 2), 23);
  ASSERT_EQ((*m3x3)(1, 0), 50);
  ASSERT_EQ((*m3x3)(1, 1), -46);
  ASSERT_EQ((*m3x3)(1, 2), 14);
  ASSERT_EQ((*m3x3)(2, 0), -18);
  ASSERT_EQ((*m3x3)(2, 1), 36);
  ASSERT_EQ((*m3x3)(2, 2), -18);
}

TEST_F(MatrixTests, CalcComplementsTest_2) {
  ASSERT_ANY_THROW(m3x2->CalcComplements());
}

//* Determinant
TEST_F(MatrixTests, DeterminantTest_1) { ASSERT_EQ(m1x1->Determinant(), 5); }

TEST_F(MatrixTests, DeterminantTest_2) { ASSERT_EQ(m3x3->Determinant(), 162); }

TEST_F(MatrixTests, DeterminantTest_3) { ASSERT_EQ(m5x5->Determinant(), 1540); }

TEST_F(MatrixTests, DeterminantTest_4) {
  ASSERT_ANY_THROW(m1x5->Determinant());
}

//* InverseMatrix
TEST_F(MatrixTests, InverseTest_1) {
  m1x1->InverseMatrix();
  ASSERT_EQ((*m1x1)(0, 0), 0.2);
}

TEST_F(MatrixTests, InverseTest_2) {
  S21Matrix m2{3, 3, 2, 3, -1, 2, 3, 4, 1, 1, 1};
  m2.InverseMatrix();
  ASSERT_DOUBLE_EQ(m2(0, 0), -0.2);
  ASSERT_DOUBLE_EQ(m2(0, 1), -0.8);
  ASSERT_DOUBLE_EQ(m2(0, 2), 3);
  ASSERT_DOUBLE_EQ(m2(1, 0), 0.4);
  ASSERT_DOUBLE_EQ(m2(1, 1), 0.6);
  ASSERT_DOUBLE_EQ(m2(1, 2), -2);
  ASSERT_DOUBLE_EQ(m2(2, 0), -0.2);
  ASSERT_DOUBLE_EQ(m2(2, 1), 0.2);
  ASSERT_DOUBLE_EQ(m2(2, 2), 0);
}

TEST_F(MatrixTests, InverseTest_3) { ASSERT_ANY_THROW(m2x3->InverseMatrix()); }

TEST_F(MatrixTests, InverseTest_4) {
  S21Matrix m{3, 3, 1, 1, 1, 1};
  // ASSERT_EQ(m.Determinant(), 0);
  ASSERT_ANY_THROW(m.InverseMatrix());
}

//* Operators
TEST_F(MatrixTests, PlusTest_1) {
  *m3x3 = *m3x3 + *m3x3;
  ASSERT_DOUBLE_EQ((*m3x3)(0, 0), 4);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 1), 8);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 2), 12);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 0), 14);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 1), 10);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 2), 6);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 0), 16);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 1), 18);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 2), 2);
}

TEST_F(MatrixTests, MinusTest_1) {
  *m3x3 = *m3x3 - *m3x3;
  ASSERT_DOUBLE_EQ((*m3x3)(0, 0), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 1), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 2), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 0), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 1), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 2), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 0), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 1), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 2), 0);
}

TEST_F(MatrixTests, MultNumberTest_1) {
  *m3x3 = *m3x3 * 2;
  ASSERT_DOUBLE_EQ((*m3x3)(0, 0), 4);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 1), 8);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 2), 12);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 0), 14);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 1), 10);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 2), 6);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 0), 16);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 1), 18);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 2), 2);
}

TEST_F(MatrixTests, MultNumberTest_2) {
  *m3x3 = 2 * *m3x3;
  ASSERT_DOUBLE_EQ((*m3x3)(0, 0), 4);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 1), 8);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 2), 12);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 0), 14);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 1), 10);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 2), 6);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 0), 16);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 1), 18);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 2), 2);
}

TEST_F(MatrixTests, MultMatrixTest_1) {
  *m2x3 = *m2x3 * *m3x3;
  ASSERT_EQ((*m2x3)(0, 0), 3);
  ASSERT_EQ((*m2x3)(0, 1), 8);
  ASSERT_EQ((*m2x3)(0, 2), 4);
  ASSERT_EQ((*m2x3)(1, 0), 57);
  ASSERT_EQ((*m2x3)(1, 1), 59);
  ASSERT_EQ((*m2x3)(1, 2), 25);
}

TEST_F(MatrixTests, EqualTest_1) { ASSERT_EQ(*m2x3 == *m2x3, true); }

TEST_F(MatrixTests, EqualTest_2) { ASSERT_EQ(*m3x3 == *m2x3, false); }

TEST_F(MatrixTests, EqualTest_3) {
  S21Matrix m(*m3x3);
  m(0, 0) = 3;
  ASSERT_EQ(*m3x3 == m, false);
}

//* ()
TEST_F(MatrixTests, BracesTest_1) { ASSERT_ANY_THROW((*m1x1)(-1, 0)); }

//* =
TEST_F(MatrixTests, RavnoTest_1) {
  S21Matrix m;
  m = *m3x3;
  ASSERT_EQ(m.EqMatrix(*m3x3), true);
}

TEST_F(MatrixTests, RavnoTest_2) {
  S21Matrix m;
  m = std::move(*m3x3);
  ASSERT_ANY_THROW((*m3x3)(1, 0));
}

//* +=
TEST_F(MatrixTests, PlusRavnoTest_1) {
  *m3x3 += *m3x3;
  ASSERT_DOUBLE_EQ((*m3x3)(0, 0), 4);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 1), 8);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 2), 12);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 0), 14);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 1), 10);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 2), 6);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 0), 16);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 1), 18);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 2), 2);
}

TEST_F(MatrixTests, MinusRavnoTest_1) {
  *m3x3 -= *m3x3;
  ASSERT_DOUBLE_EQ((*m3x3)(0, 0), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 1), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 2), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 0), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 1), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 2), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 0), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 1), 0);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 2), 0);
}

TEST_F(MatrixTests, MultNumberRavnoTest_1) {
  *m3x3 *= 2;
  ASSERT_DOUBLE_EQ((*m3x3)(0, 0), 4);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 1), 8);
  ASSERT_DOUBLE_EQ((*m3x3)(0, 2), 12);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 0), 14);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 1), 10);
  ASSERT_DOUBLE_EQ((*m3x3)(1, 2), 6);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 0), 16);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 1), 18);
  ASSERT_DOUBLE_EQ((*m3x3)(2, 2), 2);
}

TEST_F(MatrixTests, MultMatrixRavnoTest_1) {
  *m2x3 *= *m3x3;
  ASSERT_EQ((*m2x3)(0, 0), 3);
  ASSERT_EQ((*m2x3)(0, 1), 8);
  ASSERT_EQ((*m2x3)(0, 2), 4);
  ASSERT_EQ((*m2x3)(1, 0), 57);
  ASSERT_EQ((*m2x3)(1, 1), 59);
  ASSERT_EQ((*m2x3)(1, 2), 25);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  // free(cxxabiv1::cxa_get_globals());
  return RUN_ALL_TESTS();
}