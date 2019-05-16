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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        else{
            ListNode *run = head -> next;
            ListNode *prev = head;
            prev -> next = nullptr; 
            while(run != nullptr){
                prev = run;
                run = run -> next;
                prev -> next = head;
                head = prev;
            }
            return prev;
        }
    }
};

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
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution sol;
    print_list(sol.reverseList(&a));
    return 0;
}