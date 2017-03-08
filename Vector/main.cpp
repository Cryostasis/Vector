#include "Vector.h"

#include <iostream>
#include "gtest\gtest.h"

using namespace std;

TEST(Vector_test, basic_constructor_test)
{
	Vector<int> vec;
	ASSERT_EQ(vec.capacity(), 0);
	ASSERT_EQ(vec.size(), 0);
	ASSERT_EQ(vec.data(), nullptr);
}

TEST(Vector_test, first_constructor_test)
{
	Vector<int> vec(1234);
	ASSERT_EQ(vec.capacity(), 1234);
	ASSERT_EQ(vec.size(), 1234);
	ASSERT_NE(vec.data(), nullptr);
}

TEST(Vector_test, second_constructor_test)
{
	Vector<int> vec(1234, 4321);
	ASSERT_EQ(vec.capacity(), 1234);
	ASSERT_EQ(vec.size(), 1234);
	ASSERT_NE(vec.data(), nullptr);

	for (size_t i = 0; i < 1234; i++)
		ASSERT_EQ(vec[i], 4321);
}

TEST(Vector_test, third_constructor_test)
{
	double a[100];
	for (int i = 0; i < 100; i++)
		a[i] = 100 - i;

	Vector<double> vec(a, 100);
	ASSERT_EQ(vec.capacity(), 100);
	ASSERT_EQ(vec.size(), 100);
	ASSERT_NE(vec.data(), nullptr);

	for (size_t i = 0; i < 100; i++)
		ASSERT_DOUBLE_EQ(vec[i], 100 - i);
}

TEST(Vector_test, push_back_test)
{
	Vector<int> vec;
	for (int i = 5; i > 0; i--)
		vec.push_back(i);

	ASSERT_EQ(vec.size(), 5);
	for (int i = 5; i > 0; i--)
		ASSERT_EQ(vec[5 - i], i);
}

TEST(Vector_test, pop_back_test)
{
	Vector<int> vec;
	vec.push_back(123);
	vec.push_back(321);
	vec.push_back(666);
	
	vec.pop_back();
	ASSERT_EQ(vec.size(), 2);
	ASSERT_EQ(vec[0], 123);
	ASSERT_EQ(vec[1], 321);
}

TEST(Vector_test, resize_test)
{
	Vector<int> vec(50);
	vec.push_back(123);
	vec.push_back(321);
	vec.resize(100);

	ASSERT_EQ(vec.size(), 100);
	//ASSERT_EQ(vec.capacity(), 150);
	ASSERT_EQ(vec[50], 123);
	ASSERT_EQ(vec[51], 321);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
}