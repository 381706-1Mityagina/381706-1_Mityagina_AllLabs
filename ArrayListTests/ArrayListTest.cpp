#include <gtest.h>
#include "..//ArrayListLib/TArrayList.h"

TEST(TArrayList, can_create_list)
{
	ASSERT_NO_THROW(TArrayList <int> List());
}


TEST(TArrayList, can_create_list_with_positive_size)
{
	ASSERT_NO_THROW(TArrayList <int> List(3));
}

TEST(TArrayList, throws_when_create_list_with_negative_size)
{
	ASSERT_ANY_THROW(TArrayList <int> List(-1));
}

TEST(TArrayList, can_push_and_pull_beginning)
{
	TArrayList <int> List(1);

	List.PutBegin(7);
	
	ASSERT_EQ(7, List.GetBegin());
}

TEST(TArrayList, can_push_and_pull_end)
{
	TArrayList <int> List(3);
	
	List.PutEnd(2);
	List.PutEnd(4);
	List.PutEnd(7);
	
	ASSERT_EQ(7, List.GetEnd());
}


TEST(TArrayList, full_check_false)
{
	TArrayList <int> List(1);
	
	ASSERT_FALSE(List.IsFull());
}

TEST(TArrayList, full_check_true)
{
	TArrayList <int> List(1);
	
	List.PutBegin(7);
	
	ASSERT_TRUE(List.IsFull());
}

TEST(TArrayList, can_use_free_elements)
{
	TArrayList <int> List(5);

	List.PutBegin(6); // 6
	List.PutBegin(7); // 7 6
	List.PutEnd(3); // 7 6 3

	ASSERT_EQ(7, List.GetBegin()); //6 3
}

TEST(TArrayList, empty_check_false)
{
	TArrayList <int> List(1);
	
	List.PutBegin(7);
	
	ASSERT_FALSE(List.IsEmpty());
}

TEST(TArrayList, empty_check_true)
{
	TArrayList <int> List(1);
	
	ASSERT_TRUE(List.IsEmpty());
}

TEST(TArrayList, throws_when_push_begin_or_end_elem_in_full_list)
{
	TArrayList <int> List(1);
	
	List.PutBegin(7);
	
	ASSERT_ANY_THROW(List.PutBegin(2));
	ASSERT_ANY_THROW(List.PutEnd(2));
}

TEST(TArrayList, throws_when_pull_begin_or_end_elem_in_empty_list)
{
	TArrayList <int> List(1);
	
	ASSERT_ANY_THROW(List.GetBegin());
	ASSERT_ANY_THROW(List.GetEnd());
}

TEST(TArrayList, can_put_in_the_position_n)
{
	TArrayList <int> List(3);
	
	List.PutElInN(1, 0);
	
	ASSERT_EQ(1, List.GetBegin());
}
