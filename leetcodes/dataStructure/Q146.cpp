#include <vector>
using namespace std;

class cache
{
public:
    int key, value, time;
    bool vacant;
    cache() : vacant(false), key(-1), value(-1), time(-1) {}
};

class LRUCache
{
public:
    int time, size, capacity;
    vector<cache> cacheVec;
    LRUCache(int capacity) : capacity(capacity)
    {
        time = 0;
        size = 0;
        cacheVec = vector<cache>(capacity);
    }

    int get(int key)
    {
        for (cache &c : cacheVec)
        {
            if (c.key == key)
            {
                c.time = time;
                ++time;
                return c.value;
            }
        }
        return -1;
    }

    void put(int key, int value)
    {
        for (cache &c : cacheVec)
        {
            if (c.key == key)
            {
                c.key = key;
                c.value = value;
                c.time = time;
                ++time;
                return;
            }
        }
        if (size < capacity)
        {
            // put in
            for (cache &c : cacheVec)
            {
                if (!c.vacant)
                {
                    c.vacant = true;
                    c.key = key;
                    c.value = value;
                    c.time = time;
                    ++time;
                    ++size;
                    return;
                }
            }
        }
        else
        {
            int min = 0;
            for (int i = 0; i < capacity; ++i)
            {
                if (cacheVec[i].time < cacheVec[min].time)
                {
                    min = i;
                }
            }
            cacheVec[min].key = key;
            cacheVec[min].value = value;
            cacheVec[min].time = time;
            ++time;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */