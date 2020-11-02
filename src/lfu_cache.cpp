// lfu_cache.cpp

#include "lfu_cache.hpp"

namespace CACHE
{
    int LFUCache::Get(int key)
    {
        int val = -1;

        if (kv_.find(key) != kv_.end())
        {
            kv_[key] = Promote(key);
            val = kv_[key].second->second;
        }

        return val;
    }

    void LFUCache::Set(int key, int val)
    {
        if (capacity_ <= 0)
            return;

        if (kv_.find(key) == kv_.end())
        {
            if (kv_.size() == capacity_)
                Evict();

            kv_[key] = Insert(key, val);
        }
        else
        {
            kv_[key] = Promote(key);
        }
    }

    std::pair<LFUCache::frq_itr, LFUCache::val_itr> LFUCache::Promote(int key, int val = -1)
    {
        frq_itr f;
        val_itr v;

        std::tie(f, v) = kv_[key];
        frq_itr fnext = next(f);

        if (val < 0)
            val = v->second;

        int freq = f->freq + 1;
        f->vals.erase(v);

        if (f->vals.empty())
            cache_.erase(f);

        if (fnext == cache_.end() || fnext->freq != freq)
            f = cache_.insert(fnext, LFUNode(freq));
        else
            f = fnext;

        v = f->vals.insert(f->vals.end(), {key, val});

        return {f, v};
    }

    void LFUCache::Evict()
    {
        frq_itr f = cache_.begin();
        val_itr v = f->vals.begin();

        kv_.erase(v->first);
        f->vals.erase(v);

        if (f->vals.empty())
            cache_.erase(f);
    }
    std::pair<LFUCache::frq_itr, LFUCache::val_itr> LFUCache::Insert(int key, int val)
    {
        frq_itr f = cache_.begin();

        if (f == cache_.end() || f->freq != 1)
            f = cache_.insert(f, LFUNode(1));

        val_itr v = f->vals.insert(f->vals.end(), {key, val});
        
        return {f, v};
    }
}