#include "utmatrix.h"

#include <gtest.h>

//class TVectorTest : public ::testing::Test
//{
//public:
//	TVector<int> a;
//	TVector<int> b;
//
//};



TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	TVector<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(a);
	b[0] = 5;

	EXPECT_NE(a, b);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> a(5);

	ASSERT_ANY_THROW(a[-2] = 0);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> a(5);

	ASSERT_ANY_THROW(a[5] = 0);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> a(5);
	ASSERT_NO_THROW(a = a);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	TVector<int> b(5);
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	TVector<int> b;
	b = a;
	EXPECT_EQ(b.GetSize(), 5);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	TVector<int> b;
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(5);
	for (int i = 0; i < 5; i++)
		b[i] = i;

	EXPECT_EQ(a, b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	EXPECT_EQ(a, a);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(10);
	for (int i = 0; i < 5; i++)
		b[i] = i;

	EXPECT_NE(a, b);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	a = a + 5;

	TVector<int> b(5);
	for (int i = 0; i < 5; i++)
		b[i] = i + 5;

	EXPECT_EQ(a, b);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	a = a - 5;

	TVector<int> b(5);
	for (int i = 0; i < 5; i++)
		b[i] = i - 5;

	EXPECT_EQ(a, b);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	a = a * 5;

	TVector<int> b(5);
	for (int i = 0; i < 5; i++)
		b[i] = i * 5;

	EXPECT_EQ(a, b);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(5);
	for (int i = 0; i < 5; i++)
		b[i] = i;

	TVector<int> res(5);
	for (int i = 0; i < 5; i++)
		res[i] = i * 2;


	EXPECT_EQ(res, a + b);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(6);
	for (int i = 0; i < 6; i++)
		b[i] = i;

	ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(5);
	for (int i = 0; i < 5; i++)
		b[i] = i * 2;

	TVector<int> res(5);
	for (int i = 0; i < 5; i++)
		res[i] = -i;


	EXPECT_EQ(res, a - b);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(6);
	for (int i = 0; i < 6; i++)
		b[i] = i;

	ASSERT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(5);
	for (int i = 0; i < 5; i++)
		b[i] = i * 2;

	int res = 60;

	EXPECT_EQ(res, a * b);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;

	TVector<int> b(6);
	for (int i = 0; i < 6; i++)
		b[i] = i;

	ASSERT_ANY_THROW(a * b);
}

