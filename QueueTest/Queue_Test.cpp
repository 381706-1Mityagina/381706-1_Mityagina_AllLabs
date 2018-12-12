#include "..//QueueLib/Queue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue <int> V(7));
}
//------------------------------------------------------------------------
TEST(TQueue, cannot_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue <int> V(-7));
}
//------------------------------------------------------------------------
TEST(TQueue, can_do_stuff_like_put_and_get)
{
	TQueue <int> Q(1);
	
	Q.Put(7);
	
	ASSERT_EQ(7, Q.Get());
}
//------------------------------------------------------------------------
TEST(TQueue, can_tell_if_Queue_is_not_full)
{
	TQueue <int> Q(7);
	
	ASSERT_FALSE(Q.IsFull());
}
//------------------------------------------------------------------------
TEST(TQueue, can_copy_queue)
{
	TQueue<double> Q(2);
	Q.Put(5);

  EXPECT_NO_THROW(TQueue<double> Q2(Q));
}
//------------------------------------------------------------------------
TEST(TQueue, can_take_elem_from_not_empty_queue)
{
	TQueue<double> Q(2);
	
	Q.Put(1);
	
	ASSERT_NO_THROW(Q.Get());
}
//------------------------------------------------------------------------
TEST(TQueue, cant_put_elem_in_full_queue)
{
	TQueue<double> Q(1);
	
	Q.Put(1);
	
	ASSERT_ANY_THROW(Q.Put(1));
}
//------------------------------------------------------------------------
TEST(TQueue, can_take_elem_from_queue)
{
	TQueue<double> Q(1);
	
	Q.Put(5);
        TQueue<double> Q2(Q);
  
	EXPECT_EQ(5, Q2.Get());
}
//------------------------------------------------------------------------
TEST(TQueue, can_check_if_queue_is_empty_false_check)
{
	TQueue<double> Q(1);
	
	Q.Put(5);

	EXPECT_EQ(0, Q.IsEmpty());
}
//------------------------------------------------------------------------
TEST(TQueue, can_check_if_queue_is_full)
{
	TQueue<double> Q(1);
	
	Q.Put(5);

	EXPECT_EQ(1, Q.IsFull());
}
//------------------------------------------------------------------------
