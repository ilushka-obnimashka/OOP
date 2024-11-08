#include "gtest/gtest.h"
#include "../src/Cbuffer.h"


//void erase(int first, int last);*/

TEST(Working_with_buffer_elements_Tests, swap){
    size_t initialCapacity1 = 5;
    CircularBuffer<int> buffer1(initialCapacity1, 1);

    size_t initialCapacity2 = 10;
    CircularBuffer<int> buffer2(initialCapacity2, 2);

    buffer1.swap(buffer2);

    EXPECT_EQ(buffer1.getCapacity(),10);
    EXPECT_EQ(buffer1.getSize(),10);

    EXPECT_EQ(buffer2.getCapacity(),5);
    EXPECT_EQ(buffer2.getSize(),5);

    for (size_t i = 0; i<buffer1.getSize(); i++){
        EXPECT_EQ(buffer1[i],2);
        EXPECT_EQ(buffer2[i],1);
    }
}

TEST(Working_with_buffer_elements_Tests, insert){

    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
    }
    //Сдвигает буфер так, что по нулевому индексу окажется элемент
    //с индексом new_begin (индексация идет от start, (start = 0)).
    //void rotate(int new_begin)

    buffer.rotate(7);
    // buffer 7 8 9 0 1 2 3 4 5 6

    // вставляет элемент по индексу (индексация от start)
    //void insert(int pos, const value_type & item = value_type());
    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.insert(i,i);
    }
    // buffer 0 1 2 3 4 5 6 7 8 9

    // buffer 0 1 2 3 4 5 6 7 8 9
    // start = 0
    for (size_t i = 0; i<initialCapacity; i++){
        EXPECT_EQ(buffer[i],i);
    }

}

TEST(Working_with_buffer_elements_Tests, erase) {
    size_t initialCapacity = 10;
    CircularBuffer<int> buffer(initialCapacity);

    for (size_t i = 0; i < initialCapacity; i++) {
        buffer.push_back(i);
    }

    EXPECT_EQ(buffer.getSize(), initialCapacity);

    buffer.erase(2,5);
    std::vector<int> expected{0, 1, 5, 6, 7 , 8, 9};

    EXPECT_EQ(buffer.getSize(), initialCapacity - (5-2));

    for (size_t i = 0; i<buffer.getSize(); i++){
        EXPECT_EQ(buffer[i],expected[i]);
    }
}

