#include <iostream>
#include <vector>
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
    void splitList(ListNode* head, ListNode** first, ListNode** second){
        if(!head) return;
        ListNode *slow = head, *fast = head->next;
        
        while(fast){
            fast = fast->next;
            if(fast){
                slow = slow->next;
                fast = fast->next;
            }
        }

        *first = head;
        *second = slow->next;
        slow->next = nullptr;
        return;
    }

    ListNode* mergeList(ListNode* first, ListNode* second){
        ListNode *ret = nullptr;
        if(!first) return second;
        else if(!second) return first;
        else{
            if(first->val < second->val){
                ret = first;
                ret->next = mergeList(first->next, second);
            }
            else{
                ret = second;
                ret->next = mergeList(first, second->next);
            }
        }
        return ret;
    }

    void mergeSort(ListNode **headRef){
        if(!(*headRef) || !((*headRef)->next)) return;
        ListNode *head = *headRef;
        ListNode *first, *second;
        splitList(head, &first, &second);
        mergeSort(&first);
        mergeSort(&second);
        *headRef = mergeList(first, second);
        return;
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        mergeSort(&head);
        return head;
    }
};

int main(){
    Solution sol;
    ListNode* head, *result;
    ListNode h1(-1), h2(5), h3(3), h4(4), h5(0);
    head = &h1; h1.next = &h2; h2.next = &h3; h3.next = &h4; h4.next = &h5; 
    result = sol.sortList(head);
    while(result != nullptr){
        cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}