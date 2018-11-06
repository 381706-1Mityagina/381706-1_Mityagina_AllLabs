#include "../VectorLib/Vector.h"
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

TEST(TVector, can_get_size)
{
  TVector<int> a(10);

  EXPECT_EQ(10, a.GetSize);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> a(7);  
  
  ASSERT_NO_THROW(a = a); 
}

TEST(TVector, can_assign_vectors_of_equal_size) 
{ 
  TVector<int> v1(4);  
  TVector<int> v2(4);  
  
  ASSERT_NO_THROW(v1 = v2); 
}

TEST(TVector, compare_vector_with_itself_return_true) 
{
  TVector<int> v1(4);  
  
  for (int i(0); i < 4; ++i) 
   v1[i] = 1;   
  
  ASSERT_TRUE(v1 == v1);
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
