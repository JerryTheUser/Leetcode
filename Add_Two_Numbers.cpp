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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ret = l1, *pre, *pre2;
        while(l1 != nullptr && l2 != nullptr){
        	l1->val = l1->val + l2->val + carry;
        	if(l1->val > 9){
        		l1->val -= 10;
        		carry = 1;
        	}
        	else{
        		carry = 0;
        	}
        	pre = l1;
        	l1 = l1->next;
        	l2 = l2->next;
        }

        if(l2 != nullptr){
        	pre->next = l2;
        	pre = pre->next;
        }
        else if(l1 != nullptr)
        	pre = l1;
        else{
        	if(carry == 1)
        	pre->next = new ListNode(carry);
        	return ret;
        };

        while(carry == 1){
        	pre->val += carry;
        	if(pre->val > 9){
        		pre->val -= 10;
        		carry = 1;
        	}
        	else
        		carry = 0;
        	if(pre->next != nullptr)
        		pre = pre->next;       	
        	else
        		break;	
        }

        if(carry == 1)
        	pre->next = new ListNode(carry);

        return ret;
    }
};

int main(){
	Solution sol;

	ListNode *l1, *l2, *ret;
	ListNode n1(2), n2(4), n3(6), n4(9), n5(5), n6(6), n7(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n5.next = &n6;
	n6.next = &n7;
	l2 = &n1;
	l1 = &n5;

	ListNode l3(5), l4(5);

	//ret = sol.addTwoNumbers(&l3, &l4);
	ret = sol.addTwoNumbers(l1, l2);
	while(ret != nullptr){
		cout << ret->val << ' ';
		ret = ret->next;
	}
}