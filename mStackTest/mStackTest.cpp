#include "..//MStackLib/MStack.h"

#include <gtest.h>

TEST(TMStack, can_create_multistack)
{
	ASSERT_NO_THROW(TMStack<int> lost);
}

TEST(TMStack, can_create_copy)
{
	TMStack<int> mst;

	ASSERT_NO_THROW(TMStack<int> mst1(mst));
}

TEST(TMStack, cannot_create_multictack_with_negative_size)
{
	ASSERT_ANY_THROW(TMStack<int> mst(0, -1));
}

TEST(TMStack, can_get_size)
{
	TMStack<int> mst;

	ASSERT_NO_THROW(mst.GetSize);
}
