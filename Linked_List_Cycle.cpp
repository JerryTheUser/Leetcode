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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        if(head != nullptr){
            while(fast != nullptr && slow != nullptr){
                slow = slow->next;
                fast = fast->next;
                if(fast != nullptr)
                    fast = fast->next;
                else
                    return false;

                if(fast == slow)
                    return true;
            }
        }
        return false;
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
    d.next = &b;
    Solution sol;
    cout << sol.hasCycle(&a) << '\n';
    cout << sol.hasCycle(&e) << '\n';

    return 0;
}