#include "test.h"

void CopyTest::SetUpTestCase() {
  m1 = new S21Matrix(10, 10);
  // m2 = new S21Matrix(1, 1);
  // m3 = new S21Matrix();
}
void CopyTest::TearDownTestCase() {
  delete m1;
  // delete m2;
  // delete m3;
  m1 = nullptr;
}

// Constructors
TEST(ConstructorsTestGroup, Subtest_1) { ASSERT_NO_THROW(S21Matrix m(1, 1)); }
TEST(ConstructorsTestGroup, Subtest_2) { ASSERT_NO_THROW(S21Matrix m(0, 0)); }
TEST(ConstructorsTestGroup, Subtest_3) { ASSERT_NO_THROW(S21Matrix m(5, 0)); }
TEST(ConstructorsTestGroup, Subtest_4) { ASSERT_ANY_THROW(S21Matrix m(-1, 1)); }
TEST(ConstructorsTestGroup, Subtest_5) { ASSERT_NO_THROW(S21Matrix m(1, -0)); }
TEST(ConstructorsTestGroup, Subtest_6) { ASSERT_NO_THROW(S21Matrix m(5, 5)); }
TEST(ConstructorsTestGroup, Subtest_7) { ASSERT_ANY_THROW(S21Matrix m(1, -1)); }
TEST(ConstructorsTestGroup, Subtest_8) { ASSERT_NO_THROW(S21Matrix m); }

// Copy constructor
TEST_F(CopyTest, Subtest_1) {
  std::cout << "================" << (*m1)(1, 1) << "\n";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  // free(cxxabiv1::cxa_get_globals());
  return RUN_ALL_TESTS();
}