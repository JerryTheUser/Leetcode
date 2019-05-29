#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        if(l1 == nullptr && l2 == nullptr)
            return head;
        else if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        else{
            if(l1 -> val <= l2->val){
                head = l1;
                l1 = l1->next;
            }
            else{
                head = l2;
                l2 = l2->next;
            }
            ListNode *run = head;
            while(l1 != nullptr && l2 != nullptr){
                if(l1->val <= l2->val){
                    run -> next = l1;
                    l1 = l1->next;
                }
                else{
                    run -> next = l2;
                    l2 = l2->next;
                }
                run = run->next;
            }
            run -> next = (l1==nullptr) ? l2 : l1;
            return head;
        }
        return nullptr;
    }
};
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        else{
            if(l1->val < l2->val){
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else
            {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
};
*/
void print_list(ListNode *head){
    while(head != nullptr){
        cout << head -> val << ' ';
        head = head -> next;
    }
    cout << '\n';
    return;
}

int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(4);
    ListNode d(1);
    ListNode e(3);
    ListNode f(4);
    ListNode *h1 = &a;
    a.next = &b;
    b.next = &c;
    ListNode *h2 = &d;
    d.next = &e;
    e.next = &f;
    Solution sol;
    
    print_list(sol.mergeTwoLists(h1, h2));
    return 0;
}