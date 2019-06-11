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
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        int check = 0;
        int run = 0;
        ListNode *iter = head;
        while(iter != nullptr){
            iter = iter->next;
            ++length;
        }
        iter = head;
        for(run=0 ; run<length/2 ; ++run){
            check += iter->val;
            iter = iter -> next;
        }
        if(length & 1){
            iter = iter->next;
            ++run;
        }
        for( ; run<length ; ++run){
            check -= iter->val;
            iter = iter->next;
        }
        return !check;
    }
};
*/

class Solution{
private:
    ListNode *_head;
    bool recursion(ListNode* head){
        if(head == nullptr)
            return true;
        bool ret = recursion(head->next) && (head->val == _head->val);
        _head = _head->next;
        return ret;
    }
public:
    bool isPalindrome(ListNode* head){
        if(head == nullptr || head->next == nullptr)
            return true;
        _head = head;
        return recursion(head);
    }
};

int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(2);
    ListNode d(1);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution sol;
    cout << sol.isPalindrome(&a) << '\n';
    return 0;
}