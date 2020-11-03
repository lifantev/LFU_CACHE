// lfu_cache.hpp

#ifndef LFU_CACHE_HPP
#define LFU_CACHE_HPP

#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <tuple>

namespace CACHE
{
    class LFUCache final
    {
    public:
        struct LFUNode final
        {
            int freq;
            std::list<std::pair<int, int>> vals;

            LFUNode(int f = 0) : freq(f) {}
        };

        using frq_itr = typename std::list<LFUNode>::iterator;
        using val_itr = typename std::list<std::pair<int, int>>::iterator;

        LFUCache(int capacity) : capacity_(capacity) {}

        int Get(int key);

        int SoftGet(int key);

        void Set(int key, int val);

    private:
        std::pair<frq_itr, val_itr> Promote(int key, int val = -1);

        void Evict();

        std::pair<frq_itr, val_itr> Insert(int key, int val);

    private:
        int capacity_;
        std::list<LFUNode> cache_;
        std::unordered_map<int, std::pair<frq_itr, val_itr>> kv_;
    };
} // namespace CACHE

#endif // LFU_CACHE_HPP