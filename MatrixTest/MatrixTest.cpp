#include "..//Matrix.h/Matrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(7));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-7));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(7);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> m1(7);
  TMatrix<int> m3(7);
  m1[1][1] = 2;
  m3[1][1] = 2;
  TMatrix<int> m2(m1);
  EXPECT_EQ(m3, m2);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> m(7);
  EXPECT_EQ(7, m.getDlina());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> m(7);
  m[1][2] = 7;
  EXPECT_EQ(7, m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> m(7);
  ASSERT_ANY_THROW(m[-2][1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> m(7);
  ASSERT_ANY_THROW(m[9][1] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> m1(7);
  m1[1][1] = 1;
  m1 = m1;
  EXPECT_EQ(m1, m1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> m1(7);
  TMatrix<int> m2(7);
  TMatrix<int> m3(7);
  m1[1][1] = 1;
  m3[1][1] = 1;
  m2 = m1;
  EXPECT_EQ(m3, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> m1(7);
  TMatrix<int> m2(8);
  m1[1][1] = 1;
  m2 = m1;
  EXPECT_EQ(7, m2.getDlina());
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> m1(4);
  TMatrix<int> m2(4);
  m1[1][1] = 1;
  m2[1][1] = 1;
  ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> m1(4);
  m1[1][1] = 1;
  ASSERT_TRUE(m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> m1(4);
  TMatrix<int> m2(5);
  m1[1][1] = 1;
  m2[1][1] = 1;
  ASSERT_FALSE(m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> m1(3);
  TMatrix<int> m2(3);
  TMatrix<int> m3(3);
  m1[1][1] = 1;
  m2[1][1] = 3;
  m3[1][1] = 4;
  EXPECT_EQ(m3, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> m1(7);
  TMatrix<int> m2(8);
  m1[1][1] = 1;
  m2[1][1] = 3;
  m2[2][2] = 3;
  ASSERT_ANY_THROW(m1 + m2);
}
