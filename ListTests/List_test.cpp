#include "..//ListLib/TList.h"

#include <gtest.h>

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<char> l);
}

TEST(TList, can_add_element_in_empty_list)
{
	TList<char> l;
	
	ASSERT_NO_THROW(l.PutBegin('a'));
}

TEST(Tlist, cannott_get_from_empty_list)
{
	TList<char> l;

	EXPECT_ANY_THROW(l.GetBegin());
	EXPECT_ANY_THROW(l.GetEnd());
}

TEST(Tlist, cannot_view_ptr_in_empty_list)
{
	TList<char> l;
	
	ASSERT_ANY_THROW(l.viewPtr('b'));
}

TEST(Tlist, can_view_ptr)
{
	TList<char> l;
	
	l.PutEnd('a');
	
	ASSERT_NO_THROW(l.viewPtr('a'));
}

TEST(Tlist, view_is_correct)
{
	TList<char> l;
	l.PutEnd('a');
	l.PutEnd('b');

	TElement<char>* el = l.viewPtr('b');
	
	EXPECT_EQ('b', el->data);
}

TEST(Tlist, list_is_correctly_empty)
{
	TList<char> l;
	
	l.PutEnd('a');
	l.GetEnd();
	
	EXPECT_EQ(l.GetSize(), 0);

}

TEST(TList, can_add_element_in_the_end)
{
	TList<char> l;
	
	l.PutEnd('a');
	
	EXPECT_EQ('a', l.viewData(l.viewPtr('a')));
}

TEST(Tlist, can_del_element_from_the_end)
{
	TList<char> l;
	
	l.add_el_in_tail('a'); 
	l.add_el_in_tail('b');
	l.del_el_fr_tail();
	
	EXPECT_EQ('a', l.viewData(l.viewPtr('a')));
}

TEST(TList, can_add_element_in_the_beginning)
{
	TList<char> l;
	
	l.PutBegin('a');
	
	EXPECT_EQ('a', l.viewData(l.viewPtr('a')));
}

TEST(Tlist, can_del_element_from_the_beginning)
{
	TList<char> l;
	
	l.PutBegin('a');
	l.PutBegin('b');
	
	EXPECT_EQ('b', l.GetBegin());
}
