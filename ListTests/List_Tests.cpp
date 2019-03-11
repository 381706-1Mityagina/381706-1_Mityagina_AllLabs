#include "..//ListLib/TList.h"

#include <gtest.h>

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW (TList<int> lost);
}

TEST(TList, can_create_copy_of_the_list)
{
	TList<int> lost1;
  
	ASSERT_NO_THROW (TList<int> lost(lost1));
}

TEST(TList, put_begin_has_right_answer)
{
	TList<int> lost1;
	
 ASSERT_NO_THROW (lost1.AddFirst(5));
  
}

TEST(TList, can_put_end)
{
	TList<int> lost;
  
	ASSERT_NO_THROW (lost.AddLast(5));
}

TEST (TList, isFull_gives_right_answer)
{
	TList<int> lost;
  
	lost.AddLast(8);
	
  EXPECT_EQ (true, lost.isFull());
}

TEST (TList, isempty_gives_right_answer)
{
	TList<int> lost;
	
  EXPECT_EQ (true, lost.isEmpty());
}

TEST(TList, can_put_begin)
{
	TList<int> lost;
	
  ASSERT_NO_THROW (lost.AddFirst(5));
}

TEST(TList, can_check_empty_true)
{
	TList<int> lost;

	ASSERT_TRUE(lost.isEmpty());
}

TEST(TElement, can_get_data)
{
	TElement<int> element(5, 0);

	ASSERT_EQ(element.GetData(), 5);
}

TEST(TElement, can_get_next)
{
	TElement<int>* el = 0;
	TElement<int> element(5, el);

	ASSERT_EQ(element.GetNext(), el);
}

TEST(TElement, can_set_data)
{
	TElement<int> element;

	element.Set(5);

	ASSERT_EQ(element.GetData(), 5);
}

TEST(TList, can_delete_begin)
{
	TList<int> lost;

	lost.AddFirst(7);

	ASSERT_NO_THROW(lost.delFirst());
}

TEST(TList, can_delete_curr)
{
	TList<int> lost;

	lost.AddFirst(7);

	ASSERT_NO_THROW(lost.delCurrent());
}

TEST(TList, index_operator_check)
{
	TList<int> lost;

	lost.AddFirst(7);

	ASSERT_EQ(lost[1], 7);
}

TEST(TList, isfull_gives_right_answer)
{
	TList<int> lost;

	lost.AddLast(8);

	EXPECT_EQ(true, lost.isFull());
}
