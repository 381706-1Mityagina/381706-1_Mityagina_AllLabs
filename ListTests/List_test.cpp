#include "..//ListLib/TList.h"

#include <gtest.h>

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> A);
}

TEST(TList, can_add_element_in_empty_list)
{
	TList<int> A;
	
	ASSERT_NO_THROW(l.PutBegin(7));
}

TEST(Tlist, cannott_get_from_empty_list)
{
	TList<int> A;

	EXPECT_ANY_THROW(A.GetBegin());
	EXPECT_ANY_THROW(A.GetEnd());
}

TEST(Tlist, cannot_view_ptr_in_empty_list)
{
	TList<int> A;
	
	ASSERT_ANY_THROW(A.viewPtr(5));
}

TEST(Tlist, can_view_ptr)
{
	TList<int> A;
	
	A.PutEnd(5);
	
	ASSERT_NO_THROW(A.viewPtr(5));
}

TEST(Tlist, view_is_correct)
{
	TList<int> A;
	A.PutEnd(5);
	A.PutEnd(7);

	TElement<int>* el = A.viewPtr(7);
	
	EXPECT_EQ(7, el->data);
}

TEST(Tlist, list_is_correctly_empty)
{
	TList<int> A;
	
	A.PutEnd(5);
	A.GetEnd();
	
	EXPECT_EQ(A.GetSize(), 0);

}

TEST(TList, can_add_element_in_the_end)
{
	TList<int> A;
	
	A.PutEnd(5);
	
	EXPECT_EQ(5, A.viewData(A.viewPtr(5)));
}

TEST(Tlist, can_del_element_from_the_end)
{
	TList<int> A;
	
	A.PutEnd(5); 
	A.PutEnd(7);
	A.PutEnd();
	
	EXPECT_EQ(5, l.viewData(l.viewPtr(5)));
}

TEST(TList, can_add_element_in_the_beginning)
{
	TList<int> A;
	
	A.PutBegin(7);
	
	EXPECT_EQ(7, A.viewData(A.viewPtr(7)));
}

TEST(Tlist, can_del_element_from_the_beginning)
{
	TList<int> A;
	
	A.PutBegin(6);
	A.PutBegin(7);
	
	EXPECT_EQ(7, A.GetBegin());
}
