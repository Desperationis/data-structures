#include <iostream>
#include "Queue.hpp"
#include <gtest/gtest.h>

TEST(QueueTest, CorrectRealloc) {
	Queue<int> s;
	EXPECT_EQ(s.MaxLength(), 1);
	for(size_t i = 0; i < 5; i++) {
		s.Push(i);
	}
	EXPECT_EQ(s.MaxLength(), 8);

	Queue<int, 10> s2;
	EXPECT_EQ(s2.MaxLength(), 10);
	for(size_t i = 0; i < 11; i++) {
		s2.Push(i);
	}
	EXPECT_EQ(s2.MaxLength(), 20);
}

TEST(QueueTest, CorrectSize) {
	Queue<int> s;
	EXPECT_EQ(s.Length(), 0);
	for(size_t i = 0; i < 14; i++) {
		s.Push(i);
	}
	EXPECT_EQ(s.Length(), 14);

	Queue<int, 10> s2;
	EXPECT_EQ(s2.Length(), 0);
	for(size_t i = 0; i < 14; i++) {
		s2.Push(i);
	}
	EXPECT_EQ(s2.Length(), 14);
}

TEST(QueueTest, Populate) {
	Queue<int> s;
	for(size_t i = 0; i < 100; i++) {
		s.Push(i * 2);
	}
	for(int i = 99; i >= 0; i--) { // Overflow for size_t
		EXPECT_EQ(s.Pop(), i * 2);
	}

	Queue<int, 15> s2;
	for(size_t i = 0; i < 100; i++) {
		s2.Push(i * 2);
	}
	for(int i = 99; i >= 0; i--) { // Overflow for size_t
		EXPECT_EQ(s2.Pop(), i * 2);
	}
}

TEST(QueueTest, Pop) {
	Queue<int> s;
	EXPECT_THROW(s.Pop(), std::out_of_range);
	s.Push(1);
	EXPECT_NO_THROW(s.Pop());
	EXPECT_THROW(s.Pop(), std::out_of_range);

	Queue<int, 100> s2;
	EXPECT_THROW(s2.Pop(), std::out_of_range);
	s2.Push(1);
	EXPECT_NO_THROW(s2.Pop());
	EXPECT_THROW(s2.Pop(), std::out_of_range);
}

TEST(QueueTest, Peek) {
	Queue<int> s;
	EXPECT_THROW(s.Peek(), std::out_of_range);
	s.Push(1);
	EXPECT_NO_THROW(s.Peek());
	EXPECT_EQ(s.Peek(), 1);
	s.Pop();
	EXPECT_THROW(s.Peek(), std::out_of_range);

	Queue<int, 10> s2;
	EXPECT_THROW(s2.Peek(), std::out_of_range);
	s2.Push(1);
	EXPECT_NO_THROW(s2.Peek());
	EXPECT_EQ(s2.Peek(), 1);
	s2.Pop();
	EXPECT_THROW(s2.Peek(), std::out_of_range);
}

TEST(QueueTest, Access) {
	Queue<int> s;
	for(size_t i = 0; i < 100; i++) {
		s.Push(i);
	}
	
	EXPECT_EQ(s[0], 0);
	EXPECT_EQ(s[21], 21);
	EXPECT_EQ(s[68], 68);
	EXPECT_EQ(s[99], 99);

	EXPECT_THROW(s[-1], std::out_of_range);
	EXPECT_THROW(s[-100], std::out_of_range);
	EXPECT_THROW(s[100], std::out_of_range);
	EXPECT_THROW(s[1000], std::out_of_range);

	EXPECT_NO_THROW(s[0]);
	EXPECT_NO_THROW(s[10]);
	EXPECT_NO_THROW(s[52]);
	EXPECT_NO_THROW(s[99]);

	Queue<int, 24> s2;
	for(size_t i = 0; i < 100; i++) {
		s2.Push(i);
	}
	
	EXPECT_EQ(s2[0], 0);
	EXPECT_EQ(s2[21], 21);
	EXPECT_EQ(s2[68], 68);
	EXPECT_EQ(s2[99], 99);

	EXPECT_THROW(s2[-1], std::out_of_range);
	EXPECT_THROW(s2[-100], std::out_of_range);
	EXPECT_THROW(s2[100], std::out_of_range);
	EXPECT_THROW(s2[1000], std::out_of_range);

	EXPECT_NO_THROW(s2[0]);
	EXPECT_NO_THROW(s2[10]);
	EXPECT_NO_THROW(s2[52]);
	EXPECT_NO_THROW(s2[99]);
}

TEST(QueueTest, Clear) {
	Queue<int> s;
	for(size_t i = 0; i < 100; i++) {
		s.Push(i);
	}
	size_t maxSize = s.MaxLength();
	s.Clear();
	EXPECT_EQ(s.Length(), 0);
	EXPECT_THROW(s.Peek(), std::out_of_range);
	EXPECT_THROW(s.Pop(), std::out_of_range);
	EXPECT_EQ(maxSize, s.MaxLength());
	EXPECT_THROW(s[-1], std::out_of_range);
	EXPECT_THROW(s[-100], std::out_of_range);
	EXPECT_THROW(s[0], std::out_of_range);
	EXPECT_THROW(s[1], std::out_of_range);
	EXPECT_THROW(s[1000], std::out_of_range);

	Queue<int, 10> s2;
	for(size_t i = 0; i < 100; i++) {
		s2.Push(i);
	}
	size_t maxSize2 = s2.MaxLength();
	s2.Clear();
	EXPECT_EQ(s2.Length(), 0);
	EXPECT_THROW(s2.Peek(), std::out_of_range);
	EXPECT_THROW(s2.Pop(), std::out_of_range);
	EXPECT_EQ(maxSize2, s2.MaxLength());
	EXPECT_THROW(s2[-1], std::out_of_range);
	EXPECT_THROW(s2[-100], std::out_of_range);
	EXPECT_THROW(s2[0], std::out_of_range);
	EXPECT_THROW(s2[1], std::out_of_range);
	EXPECT_THROW(s2[1000], std::out_of_range);
}




int main(int argc, char** argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
