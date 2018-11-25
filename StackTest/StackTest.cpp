#include "..//Stack/Stack.h"
#include <gtest.h>

TEST(Stack, cannot_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack <int> S(-1));
}
//----------------------------------------------------------------------
TEST(Stack, can_create_copied_stack)
{
  TStack<int> s1;
  s1.Put(3);
  s1.Put(2);
  ASSERT_NO_THROW(TStack<int> s2(s1));
}
//----------------------------------------------------------------------
TEST(Stack, IsEmpty_return_1_when_empty)
{
  TStack<int> stack;
  EXPECT_EQ(1, stack.IsEmpty());
}
//----------------------------------------------------------------------
TEST(Stack, IsFull_returns_0_when_not_full)
{
  TStack<int> stack;
  stack.Put(1);
  EXPECT_EQ(0, stack.IsFull());
}
//----------------------------------------------------------------------
TEST(Stack, can_use_full_check_true)
{
  TStack <int> S(1);
  S.Put(5);
  ASSERT_TRUE(S.IsFull());
}
//----------------------------------------------------------------------
TEST(Stack, can_use_empty_check_false)
{
  TStack <int> S(1);
  S.Put(5);
  ASSERT_FALSE(S.IsEmpty());
}
//----------------------------------------------------------------------
TEST(Stack, can_use_empty_check_true)
{
  TStack <int> S(1);
  ASSERT_TRUE(S.IsEmpty());
}
//----------------------------------------------------------------------
TEST(Stack, throws_when_in_full_stack_put_elem)
{
  TStack <int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}
//----------------------------------------------------------------------
TEST(Stack, throws_when_from_empty_stack_get_elem)
{
  TStack <int> S(1);
  ASSERT_ANY_THROW(S.Get());
}
//----------------------------------------------------------------------
