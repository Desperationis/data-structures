#include <iostream>
#include "String.hpp"
#include <gtest/gtest.h>

TEST(StringTest, CorrectSize) {
	String test("Hello world!");
	EXPECT_EQ(test.Length(), 12);

	test.Append("ag");
	EXPECT_EQ(test.Length(), 14);

	test.Pop();
	test.Pop();
	test.Pop();
	EXPECT_EQ(test.Length(), 11);
}

TEST(StringTest, Append) {
	String test("Append");
	test.Append(" me");
	EXPECT_EQ(test, "Append me");
}

TEST(StringTest, AppendPop) {
	String test("Append");
	test.Append(" me");
	EXPECT_EQ(test, "Append me");
	test.Pop();
	test.Pop();
	test.Pop();
	EXPECT_EQ(test, "Append");
}

TEST(StringTest, Pop) {
	String test("Pop");
	
	test.Pop();
	EXPECT_EQ(test, "Po");
	
	test.Pop();
	EXPECT_EQ(test, "P");
	
	test.Pop();
	EXPECT_EQ(test, "");

	test.Pop();
	EXPECT_EQ(test, "");
}

TEST(StringTest, Bounds) {
	String test("Testmybounds"); // len: 12
	EXPECT_THROW(test[12], std::out_of_range);
	EXPECT_THROW(test[100], std::out_of_range);
	EXPECT_THROW(test[-1], std::out_of_range);
	EXPECT_THROW(test[-100], std::out_of_range);
	EXPECT_NO_THROW(test[0]);
	EXPECT_NO_THROW(test[7]);
	EXPECT_NO_THROW(test[3]);
}

TEST(StringTest, Access) {
	String test("accessme");
	EXPECT_EQ(test[0], 'a');
	EXPECT_EQ(test[5], 's');
	EXPECT_EQ(test[7], 'e');
}

TEST(StringTest, CopyConstructor) {
	String test("Magic the Gathering");
	String copy(test);
	EXPECT_EQ(copy, test);
	EXPECT_EQ(copy, "Magic the Gathering");
}

TEST(StringTest, Addition) {
	String test("Hello");
	String sum = test + " world!";
	EXPECT_EQ(sum, "Hello world!");

	String test2("May the force");
	String test3(" be with you.");
	String sum2 = test2 + test3;
	EXPECT_EQ(sum2, "May the force be with you.");
}

TEST(StringTest, CopyChar) {
	String test("Magic the Gathering");
	char* copy = new char[50];
	test.CopyTo(copy, 5, 0);
	EXPECT_EQ(std::strcmp(copy, "Magic"), 0);
	test.CopyTo(copy, 3, 6);
	EXPECT_EQ(std::strcmp(copy, "the"), 0);
	delete[] copy;
}

TEST(StringTest, Empty) {
	String t(nullptr);
	EXPECT_EQ(t, "");
	EXPECT_EQ(t.Length(), 0);
	EXPECT_THROW(t[0], std::out_of_range);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
