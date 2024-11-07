#include "gtest/gtest.h"
#include "../src/class_time.h"



TEST(CreationTest, DefaultConstructor){
    EXPECT_EQ(Time::GetCounter(), 0);
    Time t;
    EXPECT_EQ(Time::GetCounter(), 1);
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);

}

TEST(CreationTest, Constructor_ValidInput1) {
    Time t(10, 30, 45);
    EXPECT_EQ(t.GetHours(), 10);
    EXPECT_EQ(t.GetMinutes(), 30);
    EXPECT_EQ(t.GetSeconds(), 45);
}


TEST(CreationTest, INCORRECT_Constructor_ValidInput2) {
    Time t(10, 30, 45);
    EXPECT_EQ(t.GetHours(), 1);
    ASSERT_EQ(t.GetHours(),1); // если не выполнился, то весь тест завершится.
    EXPECT_EQ(t.GetMinutes(), 1);
    EXPECT_EQ(t.GetSeconds(), 1);

}

TEST(CreationTest, Copy_constructor) {
    Time t1(10, 30, 45);
    Time t2 = t1;
    EXPECT_EQ(t2.GetHours(), 10);
    EXPECT_EQ(t2.GetMinutes(), 30);
    EXPECT_EQ(t2.GetSeconds(), 45);
}

TEST(CreationTest, Assignment_constructor) {
    Time t1(10, 30, 45);
    Time t2(0, 0, 0);
    t2 = t1;
    EXPECT_EQ(t2.GetHours(), 10);
    EXPECT_EQ(t2.GetMinutes(), 30);
    EXPECT_EQ(t2.GetSeconds(), 45);
}

/*int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
