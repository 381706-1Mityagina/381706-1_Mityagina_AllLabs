#include "..//MStackLib/MStack.h"

#include "..//gtest/gtest.h"

TEST(TMStack, can_create_multistack)
{
	ASSERT_NO_THROW(TMStack<int> lost(1, 1));
}

TEST(TMStack, can_create_copy)
{
	TMStack<int> mst(1, 1);

	ASSERT_NO_THROW(TMStack<int> mst1(mst));
}

TEST(TMStack, cannot_create_multictack_with_negative_size)
{
	ASSERT_ANY_THROW(TMStack<int> mst(0, -1));
}

TEST(TMStack, can_get_size)
{
	TMStack<int> mst(1, 1);

	ASSERT_NO_THROW(mst.GetSize);
}
