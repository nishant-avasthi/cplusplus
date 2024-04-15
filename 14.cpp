#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
  int capacity;
  unordered_map<int, pair<int, list<int>::iterator>> cache;

  list<int> lru;
  void updateLRU(int key)
  {
    lru.erase(cache[key].second);
    lru.push_front(key);
    cache[key].second = lru.begin();
  }

public:
  LRUCache(int capacity) { this->capacity = capacity; }
  int get(int key)
  {
    if (cache.find(key) == cache.end())
      return -1;
    updateLRU(key);
    return cache[key].first;
  }
  void put(int key, int value)
  {
    if (cache.find(key) != cache.end())
    {
      cache[key].first = value;
      updateLRU(key);
      return;
    }
    if (cache.size() == capacity)
    {
      cache.erase(lru.back());
      lru.pop_back();
    }
    lru.push_front(key);
    cache[key] = {value, lru.begin()};
  }
};
int main()
{
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  cache.put(4, 4);
  cout << cache.get(1) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;
  return 0;
}