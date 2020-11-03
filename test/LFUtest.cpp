// LFUtest.cpp

#include <fstream>
#include <vector>
#include "../src/LFUCache.hpp"
#include <gtest/gtest.h>

struct CacheF : public testing::Test
{  

    int capacity, len;
    std::ifstream fin;
    std::vector<int> vals;

    static int test_counter;

    void SetUp() override
    {
        ++test_counter;
        fin.open("..\\..\\test\\LFUtest" + std::to_string(test_counter) + ".txt");
        fin >> capacity >> len;
        
        int val;
        for (int j = 0; j < len; ++j)
        {
            fin >> val;
            vals.push_back(val);
        }   
        
        fin.close();
    }
};

int CacheF::test_counter = 0;

TEST(Cache, CreatAndSimpleCache)
{
    CACHE::LFUCache lfu_cache(2);

    lfu_cache.Set(1);
    lfu_cache.Set(2);
    lfu_cache.Set(3);
    lfu_cache.Set(3);
    lfu_cache.Set(1);
    lfu_cache.Set(2);

    ASSERT_TRUE(lfu_cache.SoftGet(1) == -1);
    ASSERT_TRUE(lfu_cache.SoftGet(2) == 2);
    ASSERT_TRUE(lfu_cache.SoftGet(3) == 3);
}

TEST_F(CacheF, LFUtest1)
{
    CACHE::LFUCache lfu_cache(capacity);

    for (auto item : vals)
    {
        lfu_cache.Set(item, item);
    }

    EXPECT_EQ(lfu_cache.SoftGet(3), 3);
    EXPECT_EQ(lfu_cache.SoftGet(2), 2);
    EXPECT_EQ(lfu_cache.SoftGet(1), -1);
}

TEST_F(CacheF, LFUtest2)
{
    CACHE::LFUCache lfu_cache(capacity);

    for (auto item : vals)
    {
        lfu_cache.Set(item, item);
    }

    EXPECT_EQ(lfu_cache.SoftGet(3), 3);
    EXPECT_EQ(lfu_cache.SoftGet(2), -1);
    EXPECT_EQ(lfu_cache.SoftGet(1), 1);
}

TEST_F(CacheF, LFUtest3)
{
    CACHE::LFUCache lfu_cache(capacity);

    for (auto item : vals)
    {
        lfu_cache.Set(item, item);
    }

    EXPECT_EQ(lfu_cache.SoftGet(1), -1);
    EXPECT_EQ(lfu_cache.SoftGet(2), -1);
}

TEST_F(CacheF, LFUtest4)
{
    CACHE::LFUCache lfu_cache(capacity);

    for (auto item : vals)
    {
        lfu_cache.Set(item, item);
    }

    EXPECT_EQ(lfu_cache.SoftGet(5), 5);
    EXPECT_EQ(lfu_cache.SoftGet(2), -1);
    EXPECT_EQ(lfu_cache.SoftGet(7), 7);
    EXPECT_EQ(lfu_cache.SoftGet(1), -1);
    EXPECT_EQ(lfu_cache.SoftGet(3), 3);
}

TEST_F(CacheF, LFUtest5)
{
    CACHE::LFUCache lfu_cache(capacity);

    for (auto item : vals)
    {
        lfu_cache.Set(item, item);
    }

    EXPECT_EQ(lfu_cache.SoftGet(0), 0);
    EXPECT_EQ(lfu_cache.SoftGet(1), -1);
    EXPECT_EQ(lfu_cache.SoftGet(3), 3);
    EXPECT_EQ(lfu_cache.SoftGet(2), -1);
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}