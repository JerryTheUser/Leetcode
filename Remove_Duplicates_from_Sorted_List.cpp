#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode **ref = &head;
        while(*ref){
            if((*ref)->next && (*ref)->val == (*ref)->next->val)
                *ref = (*ref)->next;
            else
                ref = &((*ref)->next);
        }
        return head;
    }
};