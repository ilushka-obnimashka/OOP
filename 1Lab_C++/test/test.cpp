#include "gtest/gtest.h"
#include <iostream>
#include "../src/Cbuffer.cpp"




// Тестовый случай для проверки конструктора по умолчанию
TEST(CircularBufferTest, DefaultConstructor) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    // Проверка, что capacity установлено правильно

    EXPECT_EQ(buffer.getCapacity(), initialCapacity);

    // Проверка, что size установлено правильно
    EXPECT_EQ(buffer.getSize(), 0);
    EXPECT_EQ(buffer.empty(), true);
    EXPECT_EQ(buffer.reserve(), initialCapacity);

    // Проверка, что head и tail установлены правильно
    EXPECT_EQ(buffer.getTail(), 0);

    // Проверка, что буфер выделен правильно
    EXPECT_NE(buffer.getBuffer(), nullptr);
}

TEST(CircularBufferTest, CopyConstructor){
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer1(initialCapacity, 100);

    CircularBuffer<int> buffer2 = buffer1;

    EXPECT_EQ(buffer1.getCapacity(), buffer2.getCapacity());

    EXPECT_EQ(buffer1.getSize(), buffer2.getSize());

    EXPECT_EQ(buffer1.reserve(), buffer2.reserve() );

    EXPECT_EQ(buffer1.getTail(), buffer2.getTail());

    // Проверка, что буфер выделен правильно
    EXPECT_NE(buffer2.getBuffer(), nullptr);
}

TEST(CircularBufferTest, ElemConstructor){
    size_t initialCapacity = 10;
    auto elem = 100;
    CircularBuffer<int> buffer(initialCapacity, elem);
    // Проверка, что capacity установлено правильно

    EXPECT_EQ(buffer.getCapacity(), initialCapacity);

    // Проверка, что size установлено правильно
    EXPECT_EQ(buffer.getSize(), initialCapacity);
    EXPECT_EQ(buffer.empty(), false);
    EXPECT_EQ(buffer.reserve(), 0);

    // Проверка, tail установлен правильно
    EXPECT_EQ(buffer.getTail(), 0);

    // Проверка, что буфер выделен правильно
    EXPECT_NE(buffer.getBuffer(), nullptr);

    for (size_t i = 0; i < static_cast<size_t>(initialCapacity); i++){
        EXPECT_EQ(buffer[i], elem);
    }
}

TEST(CircularBufferTest, AssignmentOperator){
    size_t initialCapacity1 = 10;
    CircularBuffer<int> buffer1(initialCapacity1, 100);

    size_t initialCapacity2 = 10;
    CircularBuffer<int> buffer2(initialCapacity2, 1100);

    buffer2 = buffer1;

    EXPECT_EQ(buffer1.getCapacity(), buffer2.getCapacity());

    EXPECT_EQ(buffer1.getSize(), buffer2.getSize());

    EXPECT_EQ(buffer1.reserve(), buffer2.reserve() );

    EXPECT_EQ(buffer1.getTail(), buffer2.getTail());

    // Проверка, что буфер выделен правильно
    EXPECT_NE(buffer2.getBuffer(), nullptr);

    for (size_t i = 0; i < static_cast<size_t>(initialCapacity1); i++){
        EXPECT_EQ(buffer1[i], buffer2[i]);
    }
}


TEST(CircularBufferTest, insert){
    size_t initialCapacity = 10;
    int elem = 100;
    CircularBuffer<int> buffer(initialCapacity, elem);

    buffer.insert(4, 1234);
    EXPECT_EQ(buffer[4], 1234);
}

TEST(CircularBufferTest, swap){
    size_t initialCapacity1 = 5;
    CircularBuffer<int> buffer1(initialCapacity1, 1);

    size_t initialCapacity2 = 10;
    CircularBuffer<int> buffer2(initialCapacity2, 2);


    EXPECT_EQ(buffer1.getCapacity(),5);
    EXPECT_EQ(buffer1.getSize(),5);

    EXPECT_EQ(buffer1.getTail(),0);

    for (size_t i = 0; i<buffer1.getSize(); i++){
       EXPECT_EQ(buffer1[i],1);
    }


    EXPECT_EQ(buffer2.getCapacity(),10);
    EXPECT_EQ(buffer2.getSize(),10);

    EXPECT_EQ(buffer2.getTail(),0);

    for (size_t i = 0; i<buffer2.getSize(); i++){
        EXPECT_EQ(buffer2[i],2);
    }

    buffer1.swap(buffer2);

    EXPECT_EQ(buffer1.getCapacity(),10);
    EXPECT_EQ(buffer1.getSize(),10);
    EXPECT_EQ(buffer1.getTail(),0);

    for (size_t i = 0; i<buffer1.getSize(); i++){
        EXPECT_EQ(buffer1[i],2);
    }

}


TEST(CircularBufferTest, clear){
    size_t initialCapacity1 = 5;
    CircularBuffer<int> buffer(initialCapacity1, 1);

    EXPECT_EQ(buffer.getCapacity(),5);
    EXPECT_EQ(buffer.getSize(),5);

    EXPECT_EQ(buffer.getTail(),0);
    EXPECT_NE(buffer.getBuffer(), nullptr);

    buffer.clear();

    EXPECT_EQ(buffer.getCapacity(),5);
    EXPECT_EQ(buffer.getSize(),0);
    EXPECT_EQ(buffer.getTail(),0);
    EXPECT_EQ(buffer.getBuffer(), nullptr);

}

TEST(CircularBufferTest, OperatorIndex) {
    //const T & operator
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity, 100);

    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], 100);
    }

    //T & operator[]
    buffer[0] = 1000;
    EXPECT_EQ(buffer[0], 1000);
}

TEST(CircularBufferTest, at) {
    // работает также как и operator[], но умеет выбрасывать исключения, проверим их

    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity, 100);

    EXPECT_THROW(buffer.at(initialCapacity+1), std::out_of_range);
    EXPECT_THROW(buffer.at(-1), std::out_of_range);

}

TEST(CircularBufferTest, front_back_elem) {
    // Проверка исключений
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer1(initialCapacity);

    EXPECT_THROW(buffer1.front(), std::logic_error);
    EXPECT_THROW(buffer1.back(), std::logic_error);

    // Проверка изменения значений первого и последнего элементов
    CircularBuffer<int> buffer(initialCapacity, 101);

    buffer.front() = -1;
    buffer.back() = -2;
    EXPECT_EQ(buffer.front(), -1);
    EXPECT_EQ(buffer.back(), -2);
}

TEST(CircularBufferTest, Linearize) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    // Добавляем элементы в буфер
    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_front(i);
    }
    // Линеаризуем буфер
    buffer.linearize();
    // Проверяем, что элементы линерализированы корректно
    for (size_t i = 0; i < buffer.getSize(); i++) {
        EXPECT_EQ(buffer[i], initialCapacity - 1 - i);
    }

    // Проверяем, что tail и head установлены корректно
    EXPECT_EQ(buffer.getTail(), 0);
}

TEST (CircularBufferTest, pop_back_pop_front){
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    EXPECT_THROW(buffer.pop_back(), std::logic_error);
    EXPECT_THROW(buffer.pop_front(), std::logic_error);

    CircularBuffer<int> buffer1(initialCapacity,101);
    buffer1.pop_back();
    EXPECT_EQ(buffer1.getSize() , 9);
    buffer1.pop_front();
    EXPECT_EQ(buffer1.getSize() , 8);
}


TEST(CircularBufferTest, EQ_NE){
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer1(initialCapacity,101);

    CircularBuffer<int> buffer2(initialCapacity,101);
    EXPECT_EQ(buffer1 == buffer2, true);

    buffer2.pop_back();
    EXPECT_EQ(buffer1 == buffer2, false);

    EXPECT_EQ(buffer1 != buffer2, true);

}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}