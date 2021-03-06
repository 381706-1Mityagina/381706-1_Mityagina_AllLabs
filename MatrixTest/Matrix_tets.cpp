#include "..//MatrixLib/Matrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(7));
}
//-----------------------------------------------------------------------
TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-7));
}
//-----------------------------------------------------------------------
TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(7);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}
//-----------------------------------------------------------------------
TEST(TMatrix, can_get_size)
{
  TMatrix<int> m(7);
 
  EXPECT_EQ(7, m.GetDlina());
}
//-----------------------------------------------------------------------
TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> m(7);

  m[1][2] = 7;

  EXPECT_EQ(7, m[1][2]);
}
//-----------------------------------------------------------------------
TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> m(7);

  ASSERT_ANY_THROW(m[-2][1] = 1);
}
//-----------------------------------------------------------------------
TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> m(7);

  ASSERT_ANY_THROW(m[9][1] = 1);
}
//-----------------------------------------------------------------------
TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> m1(7);

  m1[1][1] = 1;
  m1 = m1;
  
  EXPECT_EQ(m1, m1);
}
//-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------
TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> m1(7);
  TMatrix<int> m2(8);

  m1[1][1] = 1;
  m2 = m1;
  
  EXPECT_EQ(7, m2.GetDlina());
}
//-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------
TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> m1(7);
  TMatrix<int> m2(8);

  m1[1][1] = 1;
  m2[1][1] = 3;
  m2[2][2] = 3;

  ASSERT_ANY_THROW(m1 + m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix <int> m1(4);
	TMatrix <int> m2(4);
	TMatrix <int> m3(4);

	m1[1][2] = 1;
	m2[1][2] = 3;
	m3 = m1 - m2;

	EXPECT_EQ(m3[1][2], -2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, cannot_subtract_matrixes_with_not_equal_size)
{
	TMatrix <int> m1(4);
	TMatrix <int> m2(3);

	ASSERT_ANY_THROW(m1 - m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, matrixes_are_not_equal_if_are_not_equal)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(3);

	ASSERT_TRUE(m1 != m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, An_equality_matrix_false_chack)
{
  TMatrix <int> m1(3), m2(3);
	
  for (int i = 0; i < m1.GetDlina(); i++)
    for (int j = 0; j < m1.GetDlina() - i; j++)
    {
      m1[i][j] = i*2;
      m2[i][j] = 3*(i+j);
    }
	
  ASSERT_FALSE(m1 == m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, An_equality_matrix_with_diff_size)
{
  TMatrix <int> m1(8), m2(3);
	
  ASSERT_FALSE(m1 == m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, An_inequality_matrix_true_check)
{
  TMatrix <int> m1(7), m2(7);
	
  for (int i = 0; i < m1.GetDlina(); i++)
    for (int j = 0; j < m2.GetDlina() - i; j++)
    {
      m1[i][j] = i;
      m2[i][j] = i+1+j;
    }
	
  ASSERT_TRUE(m1 != m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, multiplication_is_impossible_if_size1_is_not_equal_to_size2)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 * m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, summ_is_correct)
{
	TMatrix<int> m1(2), m2(2), m(2);

	for (int i = 0; i < m1.GetDlina(); i++)
		for (int j = 0; j < m1.GetDlina() - i; j++)
		{
			m1[i][j] = i;
			m2[i][j] = j;
			m[i][j] = m1[i][j] + m2[i][j];
		}
	 EXPECT_EQ(m, m1+ m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, thorws_when_division_matrix_with_diff_size)
{
	TMatrix <int> m1(7), m2(8);

	ASSERT_ANY_THROW(m1 / m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, thorws_when_division_matrix_with_det_eq_zero)
{
	TMatrix <int> m1(2), m2(2);

	ASSERT_ANY_THROW(m2 / m1);
}
//-----------------------------------------------------------------------
TEST(TMatrix, is_able_to_divide_matrix)
{
	TMatrix<int> m1(2), m2(2), res(2), smth(2);

	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;

	m2[0][0] = 1;
	m2[0][1] = 1;
	m2[1][0] = 1;

	res[0][0] = 1;
	res[0][1] = 1;
	res[1][0] = 1;

	smth = m1 / m2;
	EXPECT_EQ(res, smth);
}
//-----------------------------------------------------------------------
TEST(TMatrix, razn_is_correct)
{
	TMatrix<int> m1(2), m2(2), m(2);

	for (int i = 0; i < m1.GetDlina(); i++)
		for (int j = 0; j < m1.GetDlina() - i; j++)
		{
			m1[i][j] = i;
			m2[i][j] = j;
		        m[i][j] = m1[i][j] - m2[i][j];
		}
	 EXPECT_EQ(m, m1 - m2);
}
//-----------------------------------------------------------------------
TEST(TMatrix, can_multiplicate_matrix)
{
	TMatrix <int> m1(2), m2(2), res(2);
	
	m1[0][0] = 1; 
	m1[0][1] = 2; 
	m1[1][0] = 3; 

	m2[0][0] = 5;
	m2[0][1] = 6; 
	m2[1][0] = 7;

	res[0][0] = 5;
	res[0][1] = 20; 
	res[1][0] = 21; 
	
	ASSERT_TRUE(res == m1 * m2);
}
//-----------------------------------------------------------------------
