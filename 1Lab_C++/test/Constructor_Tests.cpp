#include "gtest/gtest.h"
#include "../src/Cbuffer.h"

TEST(Constructor_Tests, DefaultConstructor) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    // Проверка, что capacity установлено правильно

    EXPECT_EQ(buffer.getCapacity(), initialCapacity);

    // Проверка, что size установлено правильно
    EXPECT_EQ(buffer.getSize(), 0);
    EXPECT_EQ(buffer.empty(), true);
    EXPECT_EQ(buffer.reserve(), initialCapacity);

    // Проверка, что head и start установлены правильно
    EXPECT_EQ(buffer.getStart(), 0);

    // Проверка, что буфер выделен правильно
    EXPECT_NE(buffer.getBuffer(), nullptr);
}

TEST(Constructor_Tests, CopyConstructor){
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer1(initialCapacity, 100);

    CircularBuffer<int> buffer2 = buffer1;

    EXPECT_EQ(buffer1.getCapacity(), buffer2.getCapacity());
    EXPECT_EQ(buffer1.getSize(), buffer2.getSize());
    EXPECT_EQ(buffer1.reserve(), buffer2.reserve());
    EXPECT_EQ(buffer1.getStart(), buffer2.getStart());
    // Проверка, что буфер выделен правильно
    EXPECT_NE(buffer2.getBuffer(), nullptr);

    CircularBuffer<int> buffer3 = buffer1;
    EXPECT_EQ(buffer1.getCapacity(), buffer3.getCapacity());
    EXPECT_EQ(buffer1.getSize(), buffer3.getSize());
    EXPECT_EQ(buffer1.reserve(), buffer3.reserve());
    EXPECT_EQ(buffer1.getStart(), buffer3.getStart());
    EXPECT_NE(buffer3.getBuffer(), nullptr);

    EXPECT_EQ(buffer2.getCapacity(), buffer3.getCapacity());
    EXPECT_EQ(buffer2.getSize(), buffer3.getSize());
    EXPECT_EQ(buffer2.reserve(), buffer3.reserve());
    EXPECT_EQ(buffer2.getStart(), buffer3.getStart());
}

TEST(Constructor_Tests, ElemConstructor){
    size_t initialCapacity = 10;
    auto elem = 100;
    CircularBuffer<int> buffer(initialCapacity, elem);
    // Проверка, что capacity установлено правильно

    EXPECT_EQ(buffer.getCapacity(), initialCapacity);

    // Проверка, что size установлено правильно
    EXPECT_EQ(buffer.getSize(), initialCapacity);
    EXPECT_EQ(buffer.empty(), false);
    EXPECT_EQ(buffer.reserve(), 0);

    // Проверка, start установлен правильно
    EXPECT_EQ(buffer.getStart(), 0);

    // Проверка, что буфер выделен правильно
    EXPECT_NE(buffer.getBuffer(), nullptr);

    for (size_t i = 0; i < static_cast<size_t>(initialCapacity); i++){
        EXPECT_EQ(buffer[i], elem);
    }
}




