#include "gtest/gtest.h"
#include "../src/Cbuffer.h"

TEST(Lineraize_Test, LinearizeAfter_push_front) {
    /* тест для проверки:
    bool is_linearized() const;
    T * linearize()
    */

    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_front(i);
    }

    EXPECT_TRUE(buffer.is_linearized());

    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], initialCapacity - 1 - i);
    }

    EXPECT_EQ(buffer.getStart(), 0);

    buffer.pop_front();
    EXPECT_FALSE(buffer.is_linearized());

    buffer.linearize();

    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], initialCapacity - 2 - i);
    }

}

TEST(Lineraize_Test, LinearizeAfter_push_back) {
    /* тест для проверки:
    bool is_linearized() const;
    T * linearize()
    */
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
    }

    EXPECT_TRUE(buffer.is_linearized());

    buffer.linearize();

    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], i);
    }

    EXPECT_EQ(buffer.getStart(), 0);

    buffer.pop_back();
    EXPECT_EQ(buffer.getStart(), 0);

    EXPECT_TRUE(buffer.is_linearized());

    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], i);
    }

}


TEST(Lineraize_Test, rotate) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
    }

    buffer.rotate(9);


    std::vector<int> expected{9, 0, 1, 2, 3, 4, 5, 6, 7 ,8};
    for (size_t i = 0; i<initialCapacity; i++){
        EXPECT_EQ(buffer[i],expected[i]);
    }
}