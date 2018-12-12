#include "..//VectorLib/Vectorlib.h"
#include "gtest.h"

TEST(TVector, can_create_vector_with_pos_length)
{
  ASSERT_NO_THROW(TVector<int>(5));
}

TEST(TVector, cannot_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int>(-6));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> a(10);

  ASSERT_NO_THROW(TVector<int> b(a));
}

TEST(TVector, can_turn_mass_into_TVector)
{
	int A[] = { 1, 2, 3, 4, 5 };
	TVector<int> a(A, 5);

	ASSERT_NO_THROW(TVector<int> b(a));
}

TEST(TVector, can_get_size)
{
  TVector<int> a(10);

  EXPECT_EQ(10, a.GetDlina());
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> a(7);  
  
  ASSERT_NO_THROW(a = a); 
}

TEST(TVector, can_assign_vectors_of_equal_size) 
{ 
  TVector<int> a(4);  
  TVector<int> b(4);  
  
  ASSERT_NO_THROW(a = b); 
}

TEST(TVector, compare_vector_with_itself_return_true) 
{
  TVector<int> a(7);  
  
  for (int i(0); i < 7; ++i) 
   a[i] = 1;   
  
  ASSERT_TRUE(a == a);
}


TEST(TVector, compare_vector_with_itself_return_false)
{
	TVector<int> a(7), a1(7);

	for (int i(0); i < 7; ++i)
	{
		a[i] = 1;
		a1[i] = 2;
	}

	ASSERT_FALSE(a == a1);
}

TEST(TVector, can_compare_different_vectors_true_check)
{
	TVector <int> a(7), b(7);

	for (int i = 0; i < a.GetDlina(); i++) 
	{
		a[i] = i;
		b[i] = i;
	}

	ASSERT_FALSE(a != b);
}

TEST(TVector, can_compare_different_vectors_false_check)
{
	TVector <int> a(7), b(7);

	for (int i = 0; i < b.GetDlina(); i++) 
	{
		a[i] = i;
		b[i] = 7 * i;
	}

	ASSERT_TRUE(a != b);
}

TEST(TVector, can_compare_different_vectors_false_with_different_size)
{
	TVector <int> a(7), b(8);

	ASSERT_TRUE(a != b);
}

TEST(TVector, cannot_add_vectors_with_not_equal_size) 
{ 
  TVector<int> a1(4);  
  TVector<int> a2(5);  
  
  ASSERT_ANY_THROW(a1 + a2); 
}

TEST(TVector, cannot_subtract_vectors_with_not_equal_size) 
{
  TVector<int> a1(6);  
  TVector<int> a2(3);  
  
  ASSERT_ANY_THROW(a1 - a2); 
}

TEST(TVector, can_increase)
{
	TVector<int> a(6);

	ASSERT_NO_THROW(a++);
}

TEST(TVector, can_add_number)
{
	TVector<int> a(6);

	ASSERT_NO_THROW(a + 6);
}

TEST(TVector, can_subtract_number)
{
	TVector<int> a(6);

	ASSERT_NO_THROW(a - 6);
}

TEST(TVector, can_add_float_number)
{
	TVector<int> a(6);

	ASSERT_NO_THROW(a + 6.5);
}

TEST(TVector, can_subtract_float_number)
{
	TVector<int> a(6);

	ASSERT_NO_THROW(a - 6.5);
}

TEST(TVector, can_decrease)
{
	TVector<int> a(6);

	ASSERT_NO_THROW(a--);
}

TEST(TVector, can_multiply_vectors_of_equal_size)
{
	TVector<int> a1(6);
	TVector<int> a2(6);

	ASSERT_NO_THROW(a1*a2);
}

TEST(TVector, cannot_multiply_vectors_of_not_equal_size)
{
	TVector<int> a1(6);
	TVector<int> a2(8);

	ASSERT_ANY_THROW(a1*a2);
}

TEST(TVector, can_multiply_vector_and_const)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1*5);
}

TEST(TVector, throws_when_position_is_less_then_0)
{
	TVector<int> a1(6);

	ASSERT_ANY_THROW(a1[-5]);
}

TEST(TVector, throws_when_position_is_greatere_then_dlina)
{
	TVector<int> a1(6);

	ASSERT_ANY_THROW(a1[8]);
}

TEST(TVector, when_position_is_adequate)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1[4]);
}

TEST(TVector, sum_check)
{
	TVector<int> a1(2), a2(2), sum(2);
	int A[] = { 7, 7 };
	TVector<int> check(A, 2);
	
	for (int i = 0; i < 2; i++)
	{
		a1[i] = 1;
		a2[i] = 6;
	}
	
	sum = a1 + a2;

	ASSERT_TRUE(sum == check);
}

TEST(TVector, razn_check)
{
	TVector<int> a1(2), a2(2), razn(2);
	int A[] = { 5, 5 };
	TVector<int> check(A, 2);
	for (int i = 0; i < 2; i++)
	{
		a1[i] = 1;
		a2[i] = 6;
	}

	razn = a2 - a1;

	ASSERT_TRUE(razn == check);
}
