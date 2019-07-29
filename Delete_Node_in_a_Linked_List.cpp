#include <iostream>
#include <vector> 
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
    void deleteNode(ListNode* node) {
    	node->val  = node->next->val;
    	node->next = node->next->next;
    	return;    
    }
};

int main(){
	Solution sol;
	ListNode *head;
	ListNode n1(2), n2(4), n3(6), n4(9), n5(5), n6(6), n7(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	head = &n1;

	sol.deleteNode(head);
	while(head != nullptr){
		cout << head->val << ' ';
		head = head->next;
	}
	return 0;
}