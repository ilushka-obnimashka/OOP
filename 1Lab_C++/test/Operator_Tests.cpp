#include "gtest/gtest.h"
#include "../src/Cbuffer.h"

TEST(Operator_Tests, AssignmentOperator) {
    size_t initialCapacity1 = 10;
    CircularBuffer<int> buffer1(initialCapacity1, 1);

    size_t initialCapacity2 = 10;
    CircularBuffer<int> buffer2(initialCapacity2, 2);

    buffer2 = buffer1;
    EXPECT_EQ(buffer1.getCapacity(), buffer2.getCapacity());
    EXPECT_EQ(buffer1.getSize(), buffer2.getSize());
    EXPECT_EQ(buffer1.reserve(), buffer2.reserve());
    EXPECT_EQ(buffer1.getStart(), buffer2.getStart());


    EXPECT_NE(buffer2.getBuffer(), nullptr);

    for (size_t i = 0; i < static_cast<size_t>(initialCapacity1); i++){
        EXPECT_EQ(buffer1[i], buffer2[i]);
    }

    CircularBuffer<int> buffer3 = buffer1;
    EXPECT_EQ(buffer1.getCapacity(), buffer3.getCapacity());
    EXPECT_EQ(buffer1.getSize(), buffer3.getSize());
    EXPECT_EQ(buffer1.reserve(), buffer3.reserve());
    EXPECT_EQ(buffer1.getStart(), buffer3.getStart());

    EXPECT_NE(buffer3.getBuffer(), nullptr);

    for (size_t i = 0; i < static_cast<size_t>(initialCapacity1); i++){
        EXPECT_EQ(buffer1[i], buffer3[i]);
    }

    EXPECT_EQ(buffer2.getCapacity(), buffer3.getCapacity());
    EXPECT_EQ(buffer2.getSize(), buffer3.getSize());
    EXPECT_EQ(buffer2.reserve(), buffer3.reserve());
    EXPECT_EQ(buffer2.getStart(), buffer3.getStart());

    for (size_t i = 0; i < static_cast<size_t>(initialCapacity1); i++){
        EXPECT_EQ(buffer2[i], buffer3[i]);
    }
}

TEST(Operator_Tests, constOperatorIndex) {
    //const T & operator
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
    }

    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], i);
    }

}

TEST(Operator_Tests, linkOperatorIndex) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer[i] = i;
    }

    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], i);
    }

}

TEST(Operator_Tests, constAt) {

    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
    }

    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], i);
    }

    EXPECT_THROW(buffer.at(initialCapacity+1), std::out_of_range);
    EXPECT_THROW(buffer.at(-1), std::out_of_range);
}

TEST(Operator_Tests, linkAt) {

    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity, -1);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.at(i) = i;
    }
    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer.at(i), i);
    }

    EXPECT_THROW(buffer.at(initialCapacity+1), std::out_of_range);
    EXPECT_THROW(buffer.at(-1), std::out_of_range);
}

/*
bool operator==(const CircularBuffer<T> &a, const CircularBuffer<T> &b)
bool operator!=(const CircularBuffer<T> &a, const CircularBuffer<T> &b)
 */
TEST(Operator_Tests, EQ_NE) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer1(initialCapacity, 101);
    CircularBuffer<int> buffer2(initialCapacity, 101);

    // Проверка равенства двух одинаковых буферов
    EXPECT_EQ(buffer1 == buffer2, true);

    // Изменение одного буфера и проверка неравенства
    buffer2.pop_back();
    EXPECT_EQ(buffer1 == buffer2, false);
    EXPECT_EQ(buffer1 != buffer2, true);

    // Проверка равенства двух пустых буферов
    CircularBuffer<int> emptyBuffer1(initialCapacity);
    CircularBuffer<int> emptyBuffer2(initialCapacity);
    EXPECT_EQ(emptyBuffer1 == emptyBuffer2, true);

    // Проверка неравенства буферов с разными емкостями
    CircularBuffer<int> buffer3(initialCapacity + 1, 101);
    EXPECT_EQ(buffer1 == buffer3, false);
    EXPECT_EQ(buffer1 != buffer3, true);

    // Проверка неравенства буферов с разными размерами
    CircularBuffer<int> buffer4(initialCapacity, 101);
    buffer4.push_back(102);
    EXPECT_EQ(buffer1 == buffer4, false);
    EXPECT_EQ(buffer1 != buffer4, true);

    // Проверка неравенства буферов с разным содержимым
    CircularBuffer<int> buffer5(initialCapacity, 101);
    buffer5.push_back(102);
    buffer1.push_back(103);
    EXPECT_EQ(buffer1 == buffer5, false);
    EXPECT_EQ(buffer1 != buffer5, true);

    // Проверка равенства буферов после присваивания
    CircularBuffer<int> buffer6 = buffer1;
    EXPECT_EQ(buffer1 == buffer6, true);
    EXPECT_EQ(buffer1 != buffer6, false);

    // Проверка неравенства буферов после изменения одного из них
    buffer6.push_back(104);
    EXPECT_EQ(buffer1 == buffer6, false);
    EXPECT_EQ(buffer1 != buffer6, true);
}
