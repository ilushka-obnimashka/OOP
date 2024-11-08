#include "gtest/gtest.h"
#include "../src/Cbuffer.h"

TEST(Push_Pop_Front_Back_Tests, Push_back) {
    // для тестирования push_back, const T & back() const
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
        EXPECT_EQ(buffer.getSize(),i+1);
        EXPECT_EQ(buffer.back(), i);
    }

    size_t size = buffer.getSize();

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
        EXPECT_EQ(size,buffer.getSize());
    }

    buffer.clear();
    EXPECT_THROW(buffer.front(), std::logic_error);
}

TEST(Push_Pop_Front_Back_Tests, Push_front) {
    // для тестирования push_front, const T & front() const
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_front(i);
        EXPECT_EQ(buffer.getSize(),i+1);
        EXPECT_EQ(buffer.front(), i);
    }

    size_t size = buffer.getSize();

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_front(i);
        EXPECT_EQ(size,buffer.getSize());
    }
    buffer.clear();
    EXPECT_THROW(buffer.front(), std::logic_error);
}

TEST(Push_Pop_Front_Back_Tests, pop_back) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
    }

    size_t size = buffer.getSize() - 1;

    for (size_t i = 0; i < initialCapacity; i++, size--){
        buffer.pop_back();
        EXPECT_EQ(size,buffer.getSize());
    }
    EXPECT_THROW(buffer.pop_back(), std::logic_error);
}

TEST(Push_Pop_Front_Back_Tests, pop_front) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_front(i);
    }

    size_t size = buffer.getSize() - 1;

    for (size_t i = 0; i < initialCapacity; i++, size--){
        buffer.pop_front();
        EXPECT_EQ(size,buffer.getSize());
    }
    EXPECT_THROW(buffer.pop_front(), std::logic_error);
}

TEST(Push_Pop_Front_Back_Tests, back) {
    // для тестирования T & back() const
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity,-1);

    buffer.back() = 1;
    EXPECT_EQ(buffer.back(), 1);

    buffer.push_back(-2);
    buffer.back() = 2;

    EXPECT_EQ(buffer.back(), 2);

    buffer.clear();
    EXPECT_THROW(buffer.front() = 10, std::logic_error);
}

TEST(Push_Pop_Front_Back_Tests, front) {
    // для тестирования  T & front() const
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity,-1);

    buffer.front() = 1;
    EXPECT_EQ(buffer.front(), 1);

    buffer.push_front(-2);
    buffer.front() = 2;

    EXPECT_EQ(buffer.front(), 2);

    buffer.clear();
    EXPECT_THROW(buffer.front() = 10, std::logic_error);
}