#include <gtest.h>
#include "..//ArrayListLib/TArrayList.h"

TEST(TArrList, can_create_list)
{
	ASSERT_NO_THROW(TArrList <int> List());
}


TEST(TArrList, can_create_list_with_positive_size)
{
	ASSERT_NO_THROW(TArrList <int> List(3));
}

TEST(TArrList, throws_when_create_list_with_negative_size)
{
	ASSERT_ANY_THROW(TArrList <int> List(-1));
}

TEST(TArrList, can_push_and_pull_beginning)
{
	TArrList <int> List(1);

	List.PutBegin(7);
	
	ASSERT_EQ(7, List.GetBegin());
}

TEST(TArrList, can_push_and_pull_end)
{
	TArrList <int> List(3);
	
	List.PutEnd(2);
	List.PutEnd(4);
	List.PutEnd(7);
	
	ASSERT_EQ(7, List.GetEnd());
}


TEST(TArrList, full_check_false)
{
	TArrList <int> List(1);
	
	ASSERT_FALSE(List.IsFull());
}

TEST(TArrList, full_check_true)
{
	TArrList <int> List(1);
	
	List.PutBegin(7);
	
	ASSERT_TRUE(List.IsFull());
}

TEST(TArrList, can_use_free_elements)
{
	TArrList <int> List(5);

	List.PutBegin(6); //6
	List.PutBegin(7); //7 6
	List.PutEnd(3); //7 6 3

	ASSERT_EQ(7, List.GetBegin()); //6 3
}

TEST(TArrList, empty_check_false)
{
	TArrList <int> List(1);
	
	List.PutBegin(7);
	
	ASSERT_FALSE(List.IsEmpty());
}

TEST(TArrList, empty_check_true)
{
	TArrList <int> List(1);
	
	ASSERT_TRUE(List.IsEmpty());
}

TEST(TArrList, throws_when_push_begin_or_end_elem_in_full_list)
{
	TArrList <int> List(1);
	
	List.PutBegin(7);
	
	ASSERT_ANY_THROW(List.PutBegin(2));
	ASSERT_ANY_THROW(List.PutFinish(2));
}

TEST(TArrList, throws_when_pull_begin_or_end_elem_in_empty_list)
{
	TArrList <int> List(1);
	
	ASSERT_ANY_THROW(List.GetBegin());
	ASSERT_ANY_THROW(List.GetEnd());
}
