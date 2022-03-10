#include <unordered_map>

namespace p_138
{
    // TODO: Add a NodeHelper for test cases?
    class Node
    {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };

    class Solution {
    public:
        Node* copyRandomList(Node* head) {

            if (head == nullptr)
            {
                return nullptr;
            }

            Node* new_head = new Node(head->val);

            std::unordered_map<Node*, Node*> node_mapping;
            node_mapping.emplace(head, new_head);

            Node* taking = head->next;
            Node* new_taking = new_head;

            while (taking != nullptr)
            {
                Node* tmp = new Node(taking->val);
                new_taking->next = tmp;

                node_mapping.emplace(taking, tmp);

                new_taking = new_taking->next;
                taking = taking->next;
            }

            new_taking = new_head;
            taking = head;
            while (new_taking != nullptr)
            {
                new_taking->random = node_mapping[taking->random];

                new_taking = new_taking->next;
                taking = taking->next;
            }

            return new_head;
        }
    };
} // namespace p_138

/*
# Problem:
https://leetcode.com/problems/copy-list-with-random-pointer/

## HINT:
* Use data structure to store the mapping from original list to new list.

## Time Complexity:
BigO(n)

## Space Complexity:
BigO(n)
*/