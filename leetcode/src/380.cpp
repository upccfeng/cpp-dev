#include "assert.h"
#include <vector>
#include <unordered_map>
#include <cstdlib>

namespace p_380
{
    class RandomizedSet
    {
        std::unordered_map<int, int> hash_map;
        std::vector<int> list;

    public:
        RandomizedSet() : hash_map(), list()
        {
        }

        bool insert(int val)
        {
            if (hash_map.find(val) == hash_map.end())
            {
                list.push_back(val);
                hash_map[val] = list.size() - 1;

                return true;
            }
            else
            {
                return false;
            }
        }

        bool remove(int val)
        {
            if (hash_map.find(val) != hash_map.end())
            {
                int pos = hash_map[val];
                assert(val == list[pos]);

                int last_pos = list.size() - 1;
                int last_val = list[last_pos];
                hash_map[last_val] = pos;

                std::swap(list[pos], list[last_pos]);
                list.pop_back();

                hash_map.erase(val);

                return true;
            }
            else
            {
                return false;
            }
        }

        int getRandom() {

            int random_value = std::rand();

            int random_pos = random_value % list.size();

            return list[random_pos];
        }
    };
} // namespace p_380

/*
# Problem:
https://leetcode.com/problems/insert-delete-getrandom-o1/

## HINT:
* Use a hash map and vector
* Key in map is val, the value in map is the position of vector.
* To remove a value from vector, move the last one to the removed position and update the map to keep there is no vacancy in the array.

## Time Complexity:
BigO(1)

## Space Complexity:
BigO(n)
*/