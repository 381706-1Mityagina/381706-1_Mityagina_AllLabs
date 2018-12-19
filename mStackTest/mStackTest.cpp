#include "..//MStackLib/MStack.h"

#include "..//gtest/gtest.h"

TEST(TMStack, can_create_multistack_posotive_length)
{
	ASSERT_NO_THROW(TMStack<int> lost(5, 7));
}

TEST(TMStack, can_create_copy)
{
	TMStack<int> lost(1, 1);

	ASSERT_NO_THROW(TMStack<int> lost1(lost));
}

TEST(TMStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW (TMStack<int> lost(5, -5));
}

TEST(TMStack, can_set_smth)
{
	TMStack<int> lost(5, 15);
	
	ASSERT_NO_THROW (lost.Set(2, 3));
}

TEST(TMStack, can_get_smth)
{
	TMStack<int> lost(5, 15);
	
	lost.Set(2, 25);
	
	EXPECT_EQ(25,test1.Get(2));
}

TEST(TMStack, can_check_if_msctack_is_empty)
{
	TMStack<int> lost(5, 15);
	
	EXPECT_EQ(1, test1.isEmpty(1));
}

TEST(TMStack, can_check_if_msctack_is_full)
{
	TMStack<int> test1(3, 15);
	
	test1.Set(1, 43);
	test1.Set(1, 43);
	test1.Set(1, 43);

	EXPECT_EQ(1, test1.isFull(1));
}
