#include "..//gtest/gtest.h"
#include "..//ViewTableLib/ViewTableElem.h"
#include "..//ViewTableLib/ViewTable.h"

TEST(ViewTableElem, can_create)
{
	string key("key");
	ASSERT_NO_THROW(TViewTableElem<int> A(key, 12));
}

TEST(ViewTableElem, can_compare_elements)
{
	string kf("a");
	string ks("key");
	
	TViewTableElem<int> A(kf, 1);
	TViewTableElem<int> B(ks, 2);

	ASSERT_TRUE(A < B);
}

TEST(ViewTable, can_create_with_positive_prmtr)
{
	ASSERT_NO_THROW(TViewTable<int> hey(10));
}

TEST(ViewTable, can_not_create_with_negative_prmtr)
{
	ASSERT_ANY_THROW(TViewTable<int> hey(-10));
}

TEST(ViewTable, can_put_and_can_get)
{
	TViewTable<int> hey(10);
	string f("f");
	string s("s");
	
	hey.Put(f, 1);
	hey.Put(s, 2);
	ASSERT_TRUE(hey[f] == 1);
	ASSERT_TRUE(hey[s] == 2);
	
}

TEST(ViewTable, can_not_put_exist_elem)
{
	TViewTable<int> hey(10);
	string f = "f";
	string s = "s";

	hey.Put(f, 1);
	hey.Put(s, 2);
	ASSERT_ANY_THROW(hey.Put(s, 25));
}

TEST(ViewTable, can_delete)
{
	TViewTable<int> hey(10);
	string f("f");
	string s("s");

	hey.Put(f, 1);
	hey.Put(s, 2);
	ASSERT_NO_THROW(hey.Del(f));
	ASSERT_TRUE(hey[s] == 2);
	ASSERT_EQ(hey.GetCount(), 1);
}

TEST(ViewTable, can_not_delete_not_exist_elem)
{
	TViewTable<int> hey(10);
	string f("f");
	string s("s");
	string t("t");

	hey[f] = 1;
	hey[s] = 2;
	hey.Put(f, 3);
	hey.Put(s, 4);

	ASSERT_ANY_THROW(hey.Del(t));
}

TEST(ViewTable, can_find)
{
	TViewTable<int> hey(10);
	string f("f");
	string s("s");

	hey[f] = 1;
	hey[s] = 2;
	hey.Put(f, 3);
	hey.Put(s, 4);

	TViewTableElem<int> A = hey.Search(f);
	ASSERT_TRUE(A.GetData() == 1);
	ASSERT_TRUE(A.GetKey() == f);
}
