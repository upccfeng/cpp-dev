#include "assert.h"
#include <unordered_map>

namespace p_146
{
    class Node
    {
    public:
        int key;
        int val;
        Node* next;
        Node* pre;
        Node(int key, int val) : key(key), val(val), next(nullptr), pre(nullptr) {}
    };

    class LRUCache
    {
        int capacity;
        int size;
        std::unordered_map<int, Node*> map;
        Node* front;
        Node* back;

        void addToFirst(Node* node)
        {
            if (front == nullptr)
            {
                assert(back == nullptr);

                front = node;
                back = node;

                node->next = nullptr;
                node->pre = nullptr;
            }
            else
            {
                node->next = front;
                front->pre = node;
                front = node;
            }
        }

        void deleteNode(Node* node)
        {
            if (node->next == nullptr)
            {
                back = node->pre;
            }

            if (node->pre != nullptr)
            {
                node->pre->next = node->next;
            }
            else
            {
                front = node->next;
            }

            delete node;
        }

        int getLastKey()
        {
            return back->key;
        }

        void moveNodeToFirst(Node* node)
        {
            if (node->pre == nullptr)
            {
                return;
            }

            if (node->next == nullptr)
            {
                back = node->pre;
            }
            else
            {
                node->next->pre = node->pre;
            }

            node->pre->next = node->next;
            node->next = front;
            node->pre = nullptr;
            front->pre = node;

            front = node;
        }

    public:
        LRUCache(int capacity) : capacity(capacity), size(0), map(), front(nullptr), back(nullptr) {};

        int get(int key)
        {
            if (map.find(key) == map.end())
            {
                return -1;
            }
            else
            {
                moveNodeToFirst(map[key]);

                return map[key]->val;
            }
        }

        void put(int key, int value)
        {
            if (map.find(key) == map.end())
            {
                Node* node = new Node(key, value);
                map.insert({ key, node });

                if (size < capacity)
                {
                    addToFirst(node);
                    size++;
                }
                else
                {
                    assert(size == capacity);

                    int k = getLastKey();
                    deleteNode(map[k]);
                    addToFirst(node);

                    map.erase(k);
                    map.insert({ key, node });
                }
            }
            else
            {
                Node* node = map[key];

                node->val = value;

                moveNodeToFirst(node);
            }
        }
    };
} // namespace p_146

/*
# Problem:
https://leetcode.com/problems/lru-cache/

## HINT:
* Use Hash + Linked-List to reach BigO(1) in put/get for LRU cache.
* Hash use List Node as value.

## Time Complexity:
BigO(1)

## Space Complexity:
BigO(n)
*/