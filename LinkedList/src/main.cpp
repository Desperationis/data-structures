#include <iostream>
#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LinkedListTest, Populate) {
	LinkedList<int> list;
	for(size_t i = 0; i < 20; i++) {
		list.PushFront(i);
	}

	for(size_t i = 19; i <= 0; i--) {
		EXPECT_EQ(list.PopFront(), i);
	}
}

TEST(LinkedListTest, LengthTest) {
	LinkedList<int> list;
	for(size_t i = 0; i < 148; i++) {
		list.PushFront(i);
	}
	EXPECT_EQ(list.Length(), 148);
	list.Clear();
	EXPECT_EQ(list.Length(), 0);

	LinkedList<int> list2;
	EXPECT_EQ(list.Length(), 0);
	for(size_t i = 0; i < 148; i++) {
		list.PushFront(i);
	}
	for(size_t i = 0; i < 148; i++) {
		list.PopFront();
	}
	EXPECT_EQ(list.Length(), 0);
}

TEST(LinkedListTest, Bounds) {
	LinkedList<int> list;
	for(size_t i = 0; i < 20; i++) {
		list.PushFront(i);
	}

	EXPECT_NO_THROW(list[0]);
	EXPECT_NO_THROW(list[5]);
	EXPECT_NO_THROW(list[19]);
	EXPECT_THROW(list[20], std::out_of_range);
	EXPECT_THROW(list[2000], std::out_of_range);
	EXPECT_THROW(list[-1], std::out_of_range);
	EXPECT_THROW(list[-1000], std::out_of_range);
}

TEST(LinkedListTest, Access) {
	LinkedList<int> list;
	for(size_t i = 0; i < 200; i++) {
		list.PushFront(i * 2);
	}

	EXPECT_EQ(list[199 - 0], 0);
	EXPECT_EQ(list[199 - 34], 34 * 2);
	EXPECT_EQ(list[199 - 130], 130 * 2);
	EXPECT_EQ(list[199 - 199], 199 * 2);
}

TEST(LinkedListTest, Clear) {
	LinkedList<int> list;
	for(size_t i = 0; i < 200; i++) {
		list.PushFront(i * 3);
	}
	list.Clear();
	EXPECT_THROW(list[0], std::out_of_range);
	EXPECT_THROW(list[20], std::out_of_range);
	EXPECT_NO_THROW(list.PopFront());
}

TEST(LinkedListTest, Init) {
	LinkedList<int> list;
	EXPECT_THROW(list[0], std::out_of_range);
	EXPECT_THROW(list[20], std::out_of_range);
	EXPECT_EQ(list.Length(), 0);
	EXPECT_NO_THROW(list.PopFront());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

