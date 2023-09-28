#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

//*
class MatrixTests : public testing::Test {
 protected:
  S21Matrix *m1x1;
  S21Matrix *m3x3;
  S21Matrix *m1x5;
  S21Matrix *m5x1;

  void SetUp() {
    m1x1 = new S21Matrix{1, 1, 5};
    m3x3 = new S21Matrix{3, 3, 2, 4, 6, 7, 5, 3, 8, 9, 1};
    m1x5 = new S21Matrix(1, 5);
    m5x1 = new S21Matrix(5, 1);
  }
  void TearDown() {
    delete m1x1;
    delete m3x3;
    delete m1x5;
    delete m5x1;
    m1x1 = m3x3 = m1x5 = m5x1 = nullptr;
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
  ASSERT_EQ(m1.GetColumn(), 0);
  ASSERT_EQ(m1.GetRow(), 0);
}

TEST_F(MatrixTests, MoveTest_2) {
  S21Matrix m1(*m3x3);
  S21Matrix m2(std::move(m1));

  ASSERT_EQ(m2.EqMatrix(*m3x3), true);
  ASSERT_EQ(m1.GetColumn(), 0);
  ASSERT_EQ(m1.GetRow(), 0);
}

TEST_F(MatrixTests, MoveTest_3) {
  S21Matrix m1(*m1x5);
  S21Matrix m2(std::move(m1));

  ASSERT_EQ(m2.EqMatrix(*m1x5), true);
  ASSERT_EQ(m1.GetColumn(), 0);
  ASSERT_EQ(m1.GetRow(), 0);
}

TEST_F(MatrixTests, MoveTest_4) {
  S21Matrix m1(*m5x1);
  S21Matrix m2(std::move(m1));

  ASSERT_EQ(m2.EqMatrix(*m5x1), true);
  ASSERT_EQ(m1.GetColumn(), 0);
  ASSERT_EQ(m1.GetRow(), 0);
}

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
  ASSERT_EQ((*m1x1)(0,0), 10);
}

TEST_F(MatrixTests, MulNumTest_2) {
  m1x1->MulNumber(0.5);
  ASSERT_EQ((*m1x1)(0,0), 2.5);
}

TEST_F(MatrixTests, MulNumTest_3) {
  m1x1->MulNumber(-2);
  ASSERT_EQ((*m1x1)(0,0), -10);
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

// // Mul Matrix
// TEST_F(MatrixTests, MulNumTest_3) {
//   m1x1->MulMatrix(*m1x1);
//   ASSERT_EQ((*m1x1)(0,0), 10);
// }


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  // free(cxxabiv1::cxa_get_globals());
  return RUN_ALL_TESTS();
}