#include "../StackLib/Stack.h"

#include <gtest.h>

TEST(TStack, can_put_and_get_element)
{
	TStack<int> stack(7);
	stack.Put(1);
	stack.Put(2);
	EXPECT_EQ(2, stack.Get());
}
//----------------------------------------------------------------
TEST(TStack, check_full)
{
	TStack<int> stack(2);
	stack.Put(1);
  stack.Put(2);
	EXPECT_EQ(true, stack.IsFull());
}
//----------------------------------------------------------------
TEST(TStack, check_empty)
{
	TStack<int> stack(7);
	EXPECT_EQ(true, stack.IsEmpty());
}
//----------------------------------------------------------------
TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> stack(7));
}
//----------------------------------------------------------------
TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> stack(-7));
}
//----------------------------------------------------------------
TEST(TStack, can_create_copied_stack)
{
	TStack<int> stack(5);

	ASSERT_NO_THROW(TStack<int> stack1(stack));
}
//----------------------------------------------------------------
TEST(TStack, copied_stack_is_equal_to_the_source_one)
{
	TStack<int> stack1(7), stack2;

	for (int i = 0; i < 7; i++) 
  {
		stack1.Put(i);
	}
	stack2 = stack1;

	EXPECT_EQ(stack1, stack2);
}
//----------------------------------------------------------------
TEST(TStack, can_get_size)
{
	TStack<int> stack(5);

	for (int i = 0; i < 5; i++) 
  {
		stack.Put(i);
	}

	EXPECT_EQ(5, stack.GetSize());
}
//----------------------------------------------------------------
TEST(TStack, throws_when_get_top_in_empty_stack)
{
	TStack<int> stack(3);

	ASSERT_ANY_THROW(stack.Get());
}
//----------------------------------------------------------------
TEST(TStack, throws_when_put_an_element_in_full_stack) 
{
	TStack<int> stack(7);

	for (int i = 0; i < 7; i++) 
  {
		stack.Put(i);
	}

	ASSERT_ANY_THROW(stack.Put(7));
}
//----------------------------------------------------------------
TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> stack(7);

	ASSERT_NO_THROW(stack = stack);
}
//----------------------------------------------------------------
TEST(TStack, can_assign_stacks_of_equal_maxsize)
{
	TStack<int> stack1(7), stack2(7);

	stack2 = stack1;

	EXPECT_EQ(stack1,stack2);
}
//----------------------------------------------------------------
