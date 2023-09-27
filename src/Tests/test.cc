#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"

using namespace std;

TEST(TestGroupName1, Subtest_1) {
  EXPECT_TRUE(1 == 1);
}

TEST(TestGroupName2, Subtest_2) {
  EXPECT_FALSE('b' == 'b');
  cout << "continue test after failure" << endl;
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}