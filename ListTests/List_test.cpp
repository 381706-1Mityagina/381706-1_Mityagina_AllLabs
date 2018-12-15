#include "..//ListLib/TList.h"

#include <gtest.h>

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<char> _list);
}

TEST(TList, can_add_element_in_empty_list)
{
	TList<char> _list;
	
  ASSERT_NO_THROW(_list.PutBegin('a'));
}

TEST(Tlist, cannot_delete_from_empty_list)
{
	TList<char> _list;

	EXPECT_ANY_THROW(_list.GetBegin());
	EXPECT_ANY_THROW(_list.GetEnd());
}

TEST(Tlist, cannot_find_ptr_in_empty_list)
{
	TList<char> _list;
	
  ASSERT_ANY_THROW(_list.viewPtr('b'));
}

TEST(Tlist, can_find_ptr)
{
	TList<char> _list;
	
  _list.PutEnd('a');
	
  ASSERT_NO_THROW(_list.viewPtr('a'));
}

TEST(Tlist, find_is_not_wrong)
{
	TList<char> _list;
	_list.PutEnd('a');
	_list.PutEnd('b');

	TElement <char>* n = _list.viewPtr('b');
  
	EXPECT_EQ('b', n->data);
}

TEST(Tlist, list_is_empty_check)
{
	TList<char> _list;
  
	_list.PutEnd('a');
	_list.GetEnd();
  
	EXPECT_EQ(_list.GetSize(), 0);
}

TEST(TList, can_add_node_in_the_end)
{
	TList<char> _list;
	
  _list.PutEnd('a');
	
  EXPECT_EQ('a', _list.viewData(_list.viewPtr('a')));
}

TEST(Tlist, can_del_node_from_the_end)
{
	TList<char> _list;
  
	_list.PutEnd('a'); 
	_list.PutEnd('b');
	_list.GetEnd();
  
	EXPECT_EQ('a', l.viewData(l.viewPtr('a')));
}

TEST(TList, can_add_node_in_head)
{
	TList<char> _list;
  
	_list.PutBegin('a');
  
	EXPECT_EQ('a', _list.viewData(_list.viewPtr('a')));
}

TEST(Tlist, can_del_node_from_head)
{
	TList<char> _list;
  
	_list.PutBegin('a');
	_list.PutBegin('b');
	
  EXPECT_EQ('b', _list.GetBegin());
}
