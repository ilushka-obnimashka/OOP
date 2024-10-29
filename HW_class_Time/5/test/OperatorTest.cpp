#include "gtest/gtest.h"
#include "../src/class_time.h"
#include <iostream>


TEST(OperatorTest, add_and_assign1) {
    Time t;
    t+=60;
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(OperatorTest, add_and_assign2) {
    Time t(10,0,29);
    t+=12345;
    EXPECT_EQ(t.GetHours(),13);
    EXPECT_EQ(t.GetMinutes(),26);
    EXPECT_EQ(t.GetSeconds(),14);
}

TEST (OperatorTest, INCORRECT_add3) {
    Time t;
    t+=1121260;
    EXPECT_EQ(t.GetSeconds(), 1121260);
}

TEST (OperatorTest, sub_and_assign1) {
    Time t(10,0,29);
    t-=12345;
    EXPECT_EQ(t.GetHours(),6);
    EXPECT_EQ(t.GetMinutes(),34);
    EXPECT_EQ(t.GetSeconds(),44);
}
//https://kakoysegodnyaprazdnik.com/content/kalkulyator-slozheniya-vremeni-dnejchasov-minut-i-sekund.html

TEST (OperatorTest, eq1_sec) {
    Time t1(10,0,29);
    auto t2 = t1;
    EXPECT_TRUE(t1 == t2.ToSeconds());
}

TEST (OperatorTest, INCORRECT_eq2_sec) {
    Time t1(10,0,29);
    EXPECT_TRUE(t1 == 29);
}

TEST(TimeOperatorTests, add_seconds) {
    Time t(1, 30, 45);
    Time result = t + 15;
    EXPECT_EQ(result, Time(1, 30, 60));
}

TEST(TimeOperatorTests, sub_seconds) {
    Time t(1, 30, 45);
    Time result = t - 30;
    EXPECT_EQ(result, Time(1, 30, 15));
}

TEST(TimeOperatorTests, sub_more_seconds1) {
    Time t(1, 0, 10);
    Time result = t - 15;
    EXPECT_EQ(result, Time(0, 59, 55));
}

TEST(TimeOperatorTests, sub_more_seconds2) {
    Time t(1, 0, 10);
    Time result = t - 11215;
    EXPECT_EQ(result, Time(0,0,0));
}
