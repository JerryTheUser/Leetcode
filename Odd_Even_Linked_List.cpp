#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *odd = head, *even = head->next;
        ListNode *odd_iter = odd, *even_iter = even;
        while(odd_iter != nullptr && even_iter != nullptr && even_iter->next != nullptr){
            odd_iter->next = even_iter->next;
            odd_iter = odd_iter->next;
            even_iter->next = odd_iter->next;
            even_iter = even_iter->next;
        }
        odd_iter->next = even;
        return odd;
    }
};

int main(){
    Solution sol;
    ListNode* head;
    ListNode n1(2), n2(1), n3(3), n4(5), n5(6), n6(4), n7(7);
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    head = sol.oddEvenList(head);
    
    while(head != nullptr){
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
    return 0;
}