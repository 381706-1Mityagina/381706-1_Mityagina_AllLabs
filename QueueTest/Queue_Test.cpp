#include "Queue.h"

#include <gtest.h>

TEST(Queue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue <int> V(7));
}
//------------------------------------------------------------------------
TEST(Queue, cannot_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue <int> V(-7));
}
//------------------------------------------------------------------------
TEST(Queue, can_do_stuff_like_put_and_get)
{
	TQueue <int> Q(1);
	Q.Put(7);
	ASSERT_EQ(7, Q.Get());
}
//------------------------------------------------------------------------
TEST(Queue, can_tell_if_Queue_is_not_full)
{
	TQueue <int> Q(7);
	ASSERT_FALSE(Q.IsFull());
}
//------------------------------------------------------------------------
