#include "TList.h"

#include <gtest.h>

TEST(TList, can_add_first)
{
	TList<int> a;
	ASSERT_NO_THROW(a.AddFirst(1));
}

TEST(TList, can_add_last)
{
    TList<int> a;
	ASSERT_NO_THROW(a.AddLast(1));
}

TEST(TList, can_add_curr)
{
	 TList<int> a;
	ASSERT_NO_THROW(a.AddCurr(1));
}

TEST(TList, can_del_first)
{
	 TList<int> a;
	 a.AddFirst(1);

	ASSERT_NO_THROW(a.delFirst());
}

TEST(TList, can_del_last)
{
	 TList<int> a;
	 a.AddLast(1);

	ASSERT_NO_THROW(a.delLast());
}

TEST(TList, cant_del_curr)
{
	 TList<int> a;
	 a.AddCurr(1);

	ASSERT_NO_THROW(a.delCurr());
}

TEST(TList, can_take_val)
{
	 TList<int> a;
	 a.AddFirst(5);

	 EXPECT_EQ(5, a.getElelm());
}

TEST(TList, can_check_list_is_empty)
{
	 TList<int> a;
	 a.AddFirst(5);
	 EXPECT_EQ(false, a.isEmpty());

}
