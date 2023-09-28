#ifndef _S21_MATRIX_TESTS_H_
#define _S21_MATRIX_TESTS_H_



using namespace std;

class CopyTest : public testing::Test {
 protected:
  static S21Matrix *m1;
  static void SetUpTestCase();
  static void TearDownTestCase();
};
#endif  // _S21_MATRIX_TESTS_H_
