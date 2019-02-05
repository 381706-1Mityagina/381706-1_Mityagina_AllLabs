#include "gtest.h"
#include "Monomial.h"

TEST(TMonomial, can_create_monomial)
{
	ASSERT_NO_THROW(TMonomial moly);
}

TEST(TMonomial, can_create_monomial_with_positive_size)
{
	int mas[] = { 1, 2, 3 };

	ASSERT_NO_THROW(TMonomial moly(3, mas, 1));
}

TEST(TMonomial, cannot_create_monomial_with_negative_size)
{
	int mas[] = { 1, 2, 3 };

	ASSERT_ANY_THROW(TMonomial moly(-3, mas, 1));
}

TEST(TMonomial, can_create_copy)
{
	TMonomial moly1;

	ASSERT_NO_THROW(TMonomial moly(moly1));
}

TEST(TMonomial, can_set_power)
{
	int mas[] = { 1, 2, 3 };
	TMonomial moly;

	ASSERT_NO_THROW(moly.SetPower(mas));
}

TEST(TMonomial, can_get_power_and_gives_correct_answer)
{
	int mas[] = { 1, 2, 3 };
	int n_mas[] = { 2, 3, 4 };
	TMonomial moly(3, mas, 1);

	moly.SetPower(n_mas);

	for (int i = 0; i < 3; i++)
		ASSERT_EQ(n_mas[i], moly.GetPower()[i]);
}

TEST(TMonomial, can_get_size_and_gives_correct_answer)
{
	int mas[] = { 1, 2, 3 };

	TMonomial moly(3, mas, 1);

	EXPECT_EQ(3, moly.GetSize());
}

TEST(TMonomial, can_set_coeff)
{
	TMonomial moly;

	ASSERT_NO_THROW(moly.SetCoeff(5));
}

TEST(TMonomial, can_get_coeff_and_gives_correct_answer)
{
	TMonomial moly;

	moly.SetCoeff(5);

	EXPECT_EQ(5, moly.GetCoeff());
}

TEST(TMonomial, can_set_next)
{
	int mas[] = { 1, 2, 3 };
	int n_mas[] = { 2, 3, 4 };

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(3, n_mas, 5);

	ASSERT_NO_THROW(moly.SetNext(&n_moly));
}

TEST(TMonomial, can_get_next_and_gives_correct_answer)
{
	int mas[] = { 1, 2, 3 };
	int n_mas[] = { 2, 3, 4 };

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(3, n_mas, 5);

	moly.SetNext(&n_moly);

	EXPECT_EQ(moly.GetNext(), &n_moly);
}

TEST(TMonomial, can_set_size_and_get_it_after_changing)
{
	int mas[] = { 1, 2, 3 };

	TMonomial moly(3, mas, 1);

	moly.SetSize(2); // 2 < 3
	EXPECT_EQ(2, moly.GetSize());
	moly.SetSize(5); // 5 > 3
	EXPECT_EQ(5, moly.GetSize());
}


TEST(TMonomial, can_equate_monomials_with_equal_size)
{
	int mas[] = { 1, 2, 3 };
	int n_mas[] = { 2, 3, 4 };

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(3, n_mas, 5);

	ASSERT_NO_THROW(moly = n_moly);
}

TEST(TMonomial, cannot_equate_monomials_with_unequal_size)
{
	int mas[] = { 1, 2, 3 };
	int n_mas[] = { 2, 3, 4, 5, 6};

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(5, n_mas, 5);

	ASSERT_ANY_THROW(moly = n_moly);
}

TEST(TMonomial, can_add_or_subtract_monomials_with_equal_size)
{
	int mas[] = { 1, 2, 3 };

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(3, mas, 5);

	ASSERT_NO_THROW(moly + n_moly);
	ASSERT_NO_THROW(moly - n_moly);
}

TEST(TMonomial, cannot_add_or_subtract_monomials_with_unequal_size)
{
	int mas[] = { 1, 2, 3 };
	int n_mas[] = { 2, 3, 4, 5, 6 };

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(5, n_mas, 5);

	ASSERT_ANY_THROW(moly + n_moly);
	ASSERT_ANY_THROW(moly - n_moly);
}

TEST(TMonomial, can_compare_monomials_with_equal_size_and_gives_correct_answer)
{
	int mas[] = { 1, 2, 3 };
	int n_mas[] = { 2, 3, 4 };

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(3, n_mas, 7);

	ASSERT_NO_THROW(moly > n_moly);
	ASSERT_NO_THROW(moly < n_moly);

	ASSERT_FALSE(moly > n_moly);
	ASSERT_TRUE(moly < n_moly);
}

TEST(TMonomial, cannot_compare_monomials_with_unequal_size)
{
	int mas[] = { 1, 2, 3 };
	int n_mas[] = { 2, 3, 4, 5, 6 };

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(5, n_mas, 5);

	ASSERT_ANY_THROW(moly > n_moly);
	ASSERT_ANY_THROW(moly < n_moly);
}

TEST(TMonomial, cannot_compare_equal_monomials)
{
	int mas[] = { 1, 2, 3 };

	TMonomial moly(3, mas, 5);
	TMonomial n_moly(3, mas, 5);

	ASSERT_ANY_THROW(moly > n_moly);
	ASSERT_ANY_THROW(moly < n_moly);
}