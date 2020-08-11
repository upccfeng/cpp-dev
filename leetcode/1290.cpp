#include <iostream>
#include <vector>

/*
#include "leetcode/contest_problem_solution/1290.cpp"

int main()
{
    Solution s;
    ListNode* head;
    ListNode n1(1);
    ListNode n2(0);
    ListNode n3(1);
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    s.getDecimalValue(head);
}
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* taking = head;
        while(taking != nullptr) {
            ans = ans << 1;
            ans = ans + taking->val;
            taking = taking->next;
        }
        return ans;
    }
};