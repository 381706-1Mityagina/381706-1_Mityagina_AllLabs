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

TEST(TList, throws_when_get_begin_from_empty_list)
{
	TList<int> lost1;
  
	ASSERT_ANY_THROW (int a = lost1.GetBegin());
}

TEST(TList, put_begin_has_right_answer)
{
	TList<int> lost1;
	
  lost1.PutBegin(5);
  
	EXPECT_EQ (5, lost1.GetBegin());
}

TEST(TList, can_put_end)
{
	TList<int> lost;
  
	ASSERT_NO_THROW (lost.PutEnd(5));
}

TEST(TList, throws_when_get_end_from_empty_list)
{
	TList<int> lost;
  
	ASSERT_ANY_THROW (int a = lost.GetEnd());
}

TEST (TList, isfull_gives_right_answer)
{
	TList<int> lost;
  
	lost.PutEnd(8);
	
  EXPECT_EQ (true, lost.IsFull());
}

TEST (TList, isempty_gives_right_answer)
{
	TList<int> lost;
	
  EXPECT_EQ (true, lost.IsEmpty());
}

TEST(TList, can_put_begin)
{
	TList<int> lost;
	
  ASSERT_NO_THROW (lost.PutBegin(5));
}

TEST(TList, can_get_begin)
{
	TList<int> lost;
	
  lost.PutBegin(3);
	
  ASSERT_NO_THROW (int a = lost.GetBegin());
}

TEST(TList, can_check_empty_true)
{
	TList<int> lost;

	ASSERT_TRUE(lost.IsEmpty());
}

TEST(TList, can_get_end)
{
	TList<int> lost;

	lost.PutBegin(7);
	lost.PutBegin(6);

	ASSERT_EQ(lost.GetEnd(), 7);
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

	element.SetData(5);

	ASSERT_EQ(element.GetData(), 5);
}
