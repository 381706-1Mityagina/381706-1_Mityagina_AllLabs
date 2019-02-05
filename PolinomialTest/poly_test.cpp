#include "gtest.h"
#include "Polinomial.h"

TEST(TPolinomial, can_create_polinomial)
{
	ASSERT_NO_THROW(TPolinomial poly);
}

TEST(TPolinomial, can_create_copy)
{
	TPolinomial poly;

	ASSERT_NO_THROW(TPolinomial poly_cop(poly));
}

TEST(TPolinomial, can_get_n_and_gives_correct_answer)
{
	TPolinomial poly(5);

	EXPECT_EQ(5, poly.GetN());
}

TEST(TPolinomial, can_create_polinomial_with_positive_n)
{
	ASSERT_NO_THROW(TPolinomial poly(5));
}

TEST(TPolinomial, cannot_create_polinomial_with_negative_n)
{
	ASSERT_ANY_THROW(TPolinomial poly(-5));
}

TEST(TPolinomial, can_add_and_subtract_polinomials_with_equal_n)
{
	TPolinomial poly1(2);
	TPolinomial poly2(2);
	
	ASSERT_NO_THROW(poly1 + poly2);
	ASSERT_NO_THROW(poly1 - poly2);
}

TEST(TPolinomial, operator_plus_eq_polinomial_works_correctly)
{
	TPolinomial poly1(2);
	TPolinomial poly2(2);

	/*int mas1[] = { 1, 2 };
	int mas2[] = { 3, 4 };

	TMonomial moly1(2, mas1, 5);
	TMonomial moly2(2, mas2, 5);

	poly1 += moly1; poly2 += moly2;*/

	ASSERT_NO_THROW(poly1 += poly2);
}

TEST(TPolinomial, operator_plus_eq_monomial_works_correctly)
{
	TPolinomial poly1(2);
	TPolinomial poly2(2);

	int mas1[] = { 1, 2 };
	int mas2[] = { 3, 4 };

	TMonomial moly1(2, mas1, 5);
	TMonomial moly2(2, mas2, 5);

	ASSERT_NO_THROW(poly1 += moly1);
	ASSERT_NO_THROW(poly2 += moly2);

	EXPECT_EQ(2, poly1.GetN());
	EXPECT_EQ(2, poly2.GetN());
}

TEST(TPolinomial, operator_minus_eq_monomial_works_correctly)
{
	TPolinomial poly1(2);
	TPolinomial poly2(2);
	int mas1[] = { 1, 2 };
	int mas2[] = { 3, 4 };
	TMonomial moly1(2, mas1, 5);
	TMonomial moly2(2, mas2, 5);

	poly1 += moly2; 	poly2 += moly1;

	ASSERT_NO_THROW(poly1 -= moly1);
	ASSERT_NO_THROW(poly2 -= moly2);

	EXPECT_EQ(2, poly1.GetSize());
	EXPECT_EQ(2, poly2.GetSize());
}