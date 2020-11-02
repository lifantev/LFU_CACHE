
#include "../src/lfu_cache.hpp"
#include "gtest/gtest.h"

// struct CacheFixture : public testing::Test
// {
//     int capacity, len;

//     static void SetUpTestSuite()
//     {
//         std::cout << "SetUpTestSuite" << std::endl;
//     }

//     static void TearDownTestSuite()
//     {
//         std::cout << "TearDownTestSuite" << std::endl;
//     }

//     void SetUp() override 
//     {
//         std::cout << "SetUp" << std::endl;
//         std::cin >> capacity >> len;

//         CACHE::LFUCache lfu_cache(capacity);

//     }

//     void TearDown() override
//     {
//         std::cout << "Teardown" << std::endl;
//     }
// }

// TEST_F(CacheFixture, CreatAndSimpleCache)
// {

// }

TEST(Cache, CreatAndSimpleCache)
{
    CACHE::LFUCache lfu_cache(2);

    lfu_cache.Set(1, 1);
    lfu_cache.Set(2, 2);
    lfu_cache.Set(3, 3);
    lfu_cache.Set(3, 3);
    lfu_cache.Set(1, 1);
    lfu_cache.Set(2, 2);

    ASSERT_TRUE(lfu_cache.SoftGet(1) == -1);
    ASSERT_TRUE(lfu_cache.SoftGet(2) == 2);
    ASSERT_TRUE(lfu_cache.SoftGet(3) == 3);
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}