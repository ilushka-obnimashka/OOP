#include "gtest/gtest.h"
#include "../src/Cbuffer.h"


TEST(BufferState_Tests, Getters_and_reserve) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity, -1);

    EXPECT_EQ(buffer.getSize(), 10);
    EXPECT_EQ(buffer.getCapacity(), initialCapacity);
    EXPECT_EQ(buffer.getStart(), 0);
    EXPECT_NE(buffer.getBuffer(), nullptr);

    EXPECT_EQ(buffer.reserve(), 0);

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    EXPECT_EQ(buffer.reserve(), 0);

    buffer.clear();
    buffer.clear();

    EXPECT_EQ(buffer.getSize(), 0);
    EXPECT_EQ(buffer.getCapacity(), initialCapacity);
    EXPECT_EQ(buffer.getStart(), 0);
    EXPECT_EQ(buffer.getBuffer(), nullptr);

    EXPECT_EQ(buffer.reserve(), initialCapacity);
}

TEST(BufferState_Tests, full_empty) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity, -1);

    EXPECT_TRUE(buffer.full());
    EXPECT_FALSE(buffer.empty());

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.pop_back();
        EXPECT_FALSE(buffer.full());
    }

    EXPECT_FALSE(buffer.full());
    EXPECT_TRUE(buffer.empty());
}

TEST(BufferState_Tests, clear) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity, -1);

    EXPECT_EQ(buffer.getSize(), 10);
    EXPECT_EQ(buffer.getCapacity(), initialCapacity);
    EXPECT_EQ(buffer.getStart(), 0);

    buffer.clear();
    ASSERT_NO_THROW(buffer.clear());

    EXPECT_EQ(buffer.getSize(), 0);
    EXPECT_EQ(buffer.getCapacity(), initialCapacity);
    EXPECT_EQ(buffer.getStart(), 0);
    EXPECT_EQ(buffer.getBuffer(), nullptr);
}


TEST(BufferState_Tests, setCapacity) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity, -1);

    EXPECT_EQ(buffer.getCapacity(), initialCapacity);
    EXPECT_EQ(buffer.getSize(), 10);
    EXPECT_EQ(buffer.reserve(), 0);
    EXPECT_EQ(buffer.getStart(), 0);

    buffer.setCapacity(100);

    EXPECT_EQ(buffer.getCapacity(), 100);
    EXPECT_EQ(buffer.getSize(), 10);
    EXPECT_EQ(buffer.reserve(), 90);
    EXPECT_EQ(buffer.getStart(), 0);
}


TEST(BufferState_Tests, resize) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer1(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer1.push_back(i);
    }
    EXPECT_EQ(buffer1.getCapacity(), initialCapacity);
    EXPECT_EQ(buffer1.getSize(), 10);
    EXPECT_EQ(buffer1.reserve(), 0);

    int newCapasity = 7;

    buffer1.resize(7);
    EXPECT_EQ(buffer1.getCapacity(), initialCapacity);
    EXPECT_EQ(buffer1.getSize(), 7);
    for (size_t i = 0; i < 7; i++) {
        EXPECT_EQ(buffer1[i],i);
    }

    CircularBuffer<int> buffer2(initialCapacity);
    for (size_t i = 0; i < initialCapacity; i++) {
        buffer2.push_back(i);
    }

    EXPECT_EQ(buffer2.getCapacity(), initialCapacity);
    EXPECT_EQ(buffer2.getSize(), 10);
    EXPECT_EQ(buffer2.reserve(), 0);

    newCapasity = 20;
    buffer2.resize(20);
    EXPECT_EQ(buffer2.getCapacity(), 20);
    EXPECT_EQ(buffer2.getSize(), 10);
    EXPECT_EQ(buffer2.reserve(), 10);

    for (size_t i = 0; i < 20; i++) {
        if (i<initialCapacity) {
            EXPECT_EQ(buffer2[i],i);
        }
        else {
            EXPECT_EQ(buffer2[i], 0);
        }
    }
}