#include "../StackListLib/StackList.h"

#include <gtest.h>

TEST(TStackUsingList, can_create_stack_using_list)
{
	ASSERT_NO_THROW(TStackUsingList<int> stack);
}

TEST(TStackUsingList, can_create_copied_stack_)
{
	TStackUsingList<int> stack;

	ASSERT_NO_THROW(TStackUsingList<int> stack1(stack));
}

TEST(TStackUsingList, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStackUsingList<int> stack(5));
}

TEST(TStackUsingList, cannot_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStackUsingList<int> stack(-5));
}

TEST(TStackUsingList, can_get_msize)
{
	TStackUsingList<int> stack(5);

	EXPECT_EQ(5, stack.GetMSize());
}

TEST(TStackUsingList, can_get_size)
{
	TStackUsingList<int> stack(5);

	stack.Put(1);
	stack.Put(2);
	stack.Put(3);

	EXPECT_EQ(3, stack.GetSize());
}

TEST(TStackUsingList, can_put)
{
	TStackUsingList<int> stack(5);

	ASSERT_NO_THROW(stack.Put(5));
}

TEST(TStackUsingList, cannot_put_in_full_stack)
{
	TStackUsingList<int> stack(3);

	stack.Put(1);
	stack.Put(2);
	stack.Put(3);

	ASSERT_ANY_THROW(stack.Put(5));
}

TEST(TStackUsingList, can_del)
{
	TStackUsingList<int> stack(3);

	stack.Put(1);
	stack.Put(2);
	stack.Put(3);

	ASSERT_NO_THROW(stack.Del());
}

TEST(TStackUsingList, cannot_get_from_empty_stack)
{
	TStackUsingList<int> stack(5);

	ASSERT_ANY_THROW(stack.Get());
}

TEST(TStackUsingList, true_check_full)
{
	TStackUsingList<int> stack(2);
	
	stack.Put(1);
	stack.Put(2);
	
	EXPECT_EQ(true, stack.IsFull());
}

TEST(TStackUsingList, false_check_full)
{
	TStackUsingList<int> stack(2);

	stack.Put(1);

	EXPECT_EQ(false, stack.IsFull());
}

TEST(TStackUsingList, true_check_empty)
{
	TStackUsingList<int> stack(7);

	EXPECT_EQ(true, stack.IsEmpty());
}

TEST(TStackUsingList, false_check_empty)
{
	TStackUsingList<int> stack(7);

	stack.Put(1);

	EXPECT_EQ(false, stack.IsEmpty());
}

TEST(TStackUsingList, can_assign_stack_to_itself)
{
	TStackUsingList<int> stack(7);

	ASSERT_NO_THROW(stack = stack);
}

TEST(TStackUsingList, can_get)
{
	TStackUsingList<int> stack(5);

	stack.Put(1);
	stack.Put(2);
	stack.Put(3);

	EXPECT_EQ(3, stack.Get());
}
