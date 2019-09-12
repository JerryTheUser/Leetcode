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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
        	return head;
        ListNode *slow = head, *fast = head;
        do{
        	slow = slow->next;
        	fast = fast->next;
        	if(fast == nullptr){
        		return nullptr;
        	}
        	else{
        		fast = fast->next;
        	}
        	if(fast == nullptr)
        		return nullptr;
        }while(slow != fast);
        fast = head;
        while(fast != slow){
        	fast = fast->next;
        	slow = slow->next;
        }
        return slow;
    }
};

int main(){
	Solution sol;
	ListNode *head, *result;
	ListNode n1(3), n2(2), n3(0), n4(-4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n2;
	head = &n1;
	result = sol.detectCycle(head);
	cout << result->val << '\n';
	return 0;
}