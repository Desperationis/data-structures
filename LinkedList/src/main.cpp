#include <iostream>
#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LinkedListTest, InsertRemove) {
	LinkedList<int> list;
	for(size_t i = 0; i < 100; i++ ) {
		list.Insert(i, i * i);
	}

	// From high to low to avoid messing with previous indeces
	EXPECT_EQ(list.Remove(99), 99 * 99);	
	EXPECT_EQ(list.Remove(38), 38 * 38);	
	EXPECT_EQ(list.Remove(0), 0);	

	EXPECT_EQ(list.Remove(0), 1);	
	EXPECT_EQ(list.Remove(0), 4);	

	list.Insert(0, 14270);
	EXPECT_EQ(list.Remove(0), 14270);	

	list.Insert(39, 19230);
	EXPECT_EQ(list.Remove(39), 19230);	

	EXPECT_THROW(list.Remove(10000), std::out_of_range);
	EXPECT_THROW(list.Remove(-1), std::out_of_range);
	EXPECT_THROW(list.Remove(95), std::out_of_range);

	EXPECT_THROW(list.Insert(96, 1), std::out_of_range);
	EXPECT_THROW(list.Insert(10000, 1), std::out_of_range);
	EXPECT_THROW(list.Insert(-1, 1), std::out_of_range);
}


TEST(LinkedListTest, PopulateFront) {
	LinkedList<int> list;
	for(size_t i = 0; i < 20; i++) {
		list.PushFront(i);
	}

	for(size_t i = 19; i <= 0; i--) {
		EXPECT_EQ(list.PopFront(), i);
	}
}

TEST(LinkedListTest, PopulateBack) {
	LinkedList<int> list;
	for(size_t i = 0; i < 20; i++) {
		list.PushBack(i);
	}

	for(size_t i = 0; i < 20; i++) {
		EXPECT_EQ(list.PopFront(), i);
	}
}

TEST(LinkedListTest, PopBack) {
	LinkedList<int> list2;
	for(size_t i = 0; i < 20; i++) {
		list2.PushFront(i);
	}
	for(size_t i = 0; i < 20; i++) {
		EXPECT_EQ(list2.PopBack(), i);
	}

	LinkedList<int> list;
	for(size_t i = 0; i < 20; i++) {
		list.PushBack(i);
	}

	for(int i = 19; i >= 0; i--) { // Must be int for negatives
		EXPECT_EQ(list.PopBack(), i);
	}
}

TEST(LinkedListTest, LengthTestFront) {
	LinkedList<int> list;
	for(size_t i = 0; i < 148; i++) {
		list.PushFront(i);
	}
	EXPECT_EQ(list.Length(), 148);
	list.Clear();
	EXPECT_EQ(list.Length(), 0);

	LinkedList<int> list2;
	EXPECT_EQ(list2.Length(), 0);
	for(size_t i = 0; i < 148; i++) {
		list2.PushFront(i);
	}
	for(size_t i = 0; i < 148; i++) {
		list2.PopFront();
	}
	EXPECT_EQ(list2.Length(), 0);

	LinkedList<int> list3;
	EXPECT_EQ(list3.Length(), 0);
	for(size_t i = 0; i < 148; i++) {
		list3.PushFront(i);
	}
	for(size_t i = 0; i < 148; i++) {
		list3.PopBack();
	}
	EXPECT_EQ(list3.Length(), 0);
}

TEST(LinkedListTest, LengthTestBack) {
	LinkedList<int> list;
	for(size_t i = 0; i < 148; i++) {
		list.PushBack(i);
	}
	EXPECT_EQ(list.Length(), 148);
	list.Clear();
	EXPECT_EQ(list.Length(), 0);

	LinkedList<int> list2;
	EXPECT_EQ(list2.Length(), 0);
	for(size_t i = 0; i < 148; i++) {
		list2.PushBack(i);
	}
	for(size_t i = 0; i < 148; i++) {
		list2.PopFront();
	}
	EXPECT_EQ(list2.Length(), 0);

	LinkedList<int> list3;
	EXPECT_EQ(list3.Length(), 0);
	for(size_t i = 0; i < 148; i++) {
		list3.PushBack(i);
	}
	for(size_t i = 0; i < 148; i++) {
		list3.PopBack();
	}
	EXPECT_EQ(list3.Length(), 0);
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

	LinkedList<int> list2;
	for(size_t i = 0; i < 20; i++) {
		list2.PushBack(i);
	}

	EXPECT_NO_THROW(list2[0]);
	EXPECT_NO_THROW(list2[5]);
	EXPECT_NO_THROW(list2[19]);
	EXPECT_THROW(list2[20], std::out_of_range);
	EXPECT_THROW(list2[2000], std::out_of_range);
	EXPECT_THROW(list2[-1], std::out_of_range);
	EXPECT_THROW(list2[-1000], std::out_of_range);
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

	LinkedList<int> list2;
	for(size_t i = 0; i < 200; i++) {
		list2.PushBack(i * 2);
	}

	EXPECT_EQ(list2[0], 0);
	EXPECT_EQ(list2[34], 34 * 2);
	EXPECT_EQ(list2[130], 130 * 2);
	EXPECT_EQ(list2[199], 199 * 2);
}

TEST(LinkedListTest, Clear) {
	LinkedList<int> list;
	for(size_t i = 0; i < 200; i++) {
		list.PushFront(i * 3);
	}
	list.Clear();
	EXPECT_THROW(list[0], std::out_of_range);
	EXPECT_THROW(list[20], std::out_of_range);
	EXPECT_THROW(list.PopFront(), std::out_of_range);
	EXPECT_THROW(list.PopBack(), std::out_of_range);
	EXPECT_THROW(list.Remove(0), std::out_of_range);
}

TEST(LinkedListTest, Init) {
	LinkedList<int> list;
	EXPECT_THROW(list[0], std::out_of_range);
	EXPECT_THROW(list[20], std::out_of_range);
	EXPECT_EQ(list.Length(), 0);
	EXPECT_THROW(list.PopFront(), std::out_of_range);
	EXPECT_THROW(list.PopBack(), std::out_of_range);
	EXPECT_THROW(list.Remove(0), std::out_of_range);
	EXPECT_NO_THROW(list.Insert(0, 1));
}

int main(int argc, char** argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

