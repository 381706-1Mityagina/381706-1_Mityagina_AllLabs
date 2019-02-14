#include "../PolandLib/Poland.h"

#include <gtest.h>


TEST(ReversePolishNotation, can_get_priority)
{
	EXPECT_EQ(GetPriority('+'), 2);
	EXPECT_EQ(GetPriority('+'), 2);
	EXPECT_EQ(GetPriority('*'), 3);
	EXPECT_EQ(GetPriority('/'), 3);
	EXPECT_EQ(GetPriority(')'), 1);
	EXPECT_EQ(GetPriority('('), 1);
}

TEST(ReversePolishNotation, cannot_get_priority_for_not_operation_symbol)
{
	EXPECT_EQ(0, GetPriority('#'));
}

TEST(ReversePolishNotation, can_check_if_is_an_operation_true_check)
{
	EXPECT_EQ(IsOperation('+'), true);
	EXPECT_EQ(IsOperation('+'), true);
	EXPECT_EQ(IsOperation('*'), true);
	EXPECT_EQ(IsOperation('/'), true);
	EXPECT_EQ(IsOperation(')'), true);
	EXPECT_EQ(IsOperation('('), true);
}

TEST(ReversePolishNotation, can_check_if_is_an_operation_false_check)
{
	EXPECT_EQ(IsOperation('#'), false);
}

TEST(ReversePolishNotation, can_turn_into_RevPolNot)
{
	char *a = "(-19+8*7+98)";
	TString example(a);
	TQueue<char> B;

	ASSERT_NO_THROW(B = ToPolish(example));
}

TEST(ReversePolishNotation, works_correctly_when_turn_into_RevPolNot)
{
	char a[] = "8-9";
	TString A(a);
	TQueue<char> B;

	B = ToPolish(A);

	EXPECT_EQ('{', B.Get());
	EXPECT_EQ('8', B.Get());
	EXPECT_EQ('}', B.Get());
	EXPECT_EQ('{', B.Get());
	EXPECT_EQ('9', B.Get());
	EXPECT_EQ('}', B.Get());
	EXPECT_EQ('-', B.Get());
}

TEST(ReversePolishNotation, works_correctly_when_get_rez)
{
	char a[] = "8-9";
	TString A(a);
	TQueue<char> B;

	B = ToPolish(A);

	ASSERT_NO_THROW(GettingRez(B));
	EXPECT_EQ(GettingRez(B), -1);
}

TEST(ReversePolishNotation, works_correctly_when_opsk_does_not_eq_clsk)
{
	char a[] = "-5+8)";
	char b[] = "(-5+8";
	char c[] = "-5+8))";

	TString A(a), D(b), E(c);
	TQueue<char> B, F, K;

	ASSERT_ANY_THROW(B = ToPolish(A));
	ASSERT_ANY_THROW(F = ToPolish(D));
	ASSERT_ANY_THROW(K = ToPolish(E));
}

TEST(ReversePolishNotation, works_correctly_when_there_is_an_unacceptable_symbol)
{
	char a[] = "-5#8";
	TString A(a);
	TQueue<char> B;

	ASSERT_ANY_THROW(B = ToPolish(A));
}

TEST(ReversePolishNotation, works_correctly_when_the_first_one_is_an_operation_not_minus)
{
	char a[] = "+5+8";
	char b[] = "*5+8";
	char c[] = "/5+8";

	TString A(a), D(b), E(c);
	TQueue<char> B, F, K;

	ASSERT_ANY_THROW(B = ToPolish(A));
	ASSERT_ANY_THROW(F = ToPolish(D));
	ASSERT_ANY_THROW(K = ToPolish(E));
}

TEST(ReversePolishNotation, can_work_with_two_dig_num)
{
	char a[] = "45+5";
	TString A(a);
	TQueue<char> B;

	B = ToPolish(A);

	EXPECT_EQ(GettingRez(B), 50);
}

TEST(ReversePolishNotation, can_add_subtr_mult_del)

{
	char a[] = "5+8";
	char b[] = "5-8";
	char c[] = "5*8";
	char d[] = "8/4";
	TString A(a), D(b), E(c), L(d);
	TQueue<char> B, F, K, M;

	B = ToPolish(A);
	F = ToPolish(D);
	K = ToPolish(E);
	M = ToPolish(L);

	EXPECT_EQ(GettingRez(B), 13);
	EXPECT_EQ(GettingRez(F), -3);
	EXPECT_EQ(GettingRez(K), 40);
	EXPECT_EQ(GettingRez(M), 2);
}

TEST(ReversePolishNotation, can_notwork_without_outer_brackets)
{
	char b[] = "-1-3*7+8/2";	
	TString D(b);
	TQueue<char> F;

	ASSERT_ANY_THROW(F = ToPolish(D));
}

TEST(TString, can_create_string)
{
	ASSERT_NO_THROW(TString A);
}

TEST(TString, can_create_copy)
{
	TString B;

	ASSERT_NO_THROW(TString A(B));
}

TEST(TString, can_do_stuff_like_this_with_char_array)
{
	char a[] = "((44-25)*17+9)";

	ASSERT_NO_THROW(TString Example(a));
}

TEST(TString, can_get_size)
{
	char a[] = "((44-25)*17+9)";
	TString Example(a);

	EXPECT_EQ(15, Example.GetSize());
}

TEST(TString, can_add)
{
	char a[] = "5+8";
	char b[] = "5-8";
	
	TString A(a), B(b);

	ASSERT_NO_THROW(A+B);
}

TEST(TString, can_assign)
{
	TString A, B;

	ASSERT_NO_THROW(A = B);
}

TEST(TString, throws_when_index_is_negative)
{
	char a[] = "(44-25)*17+9";
	TString Example(a);

	ASSERT_ANY_THROW(Example[-2]);
}

TEST(TString, throws_when_index_is_grater_then_the_size)
{
	char a[] = "(44-25)*17+9";
	TString Example(a);

	ASSERT_ANY_THROW(Example[20]);
}

TEST(TString, can_get_el_with_positive_index_or_zero)
{
	char a[] = "(44-25)*17+9";
	TString Example(a);

	ASSERT_NO_THROW(Example[0]);
	ASSERT_NO_THROW(Example[5]);

	EXPECT_EQ(Example[0], '(');
	EXPECT_EQ(Example[5], '5');
}
