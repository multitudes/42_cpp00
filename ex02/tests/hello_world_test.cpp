#include <gtest/gtest.h>

TEST(HelloWorldTest, Test1) {
    // Test case 1
    ASSERT_EQ(2 + 2, 4);
}

TEST(HelloWorldTest, Test2) {
    // Test case 2
    ASSERT_TRUE(true);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}