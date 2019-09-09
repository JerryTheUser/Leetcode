#include <iostream>
#include <vector>
#include <unordered_set>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        ListNode *ret = nullptr, *iter = headA;
        while(iter != nullptr){
       		set.insert(iter);
       		iter = iter->next;
    	}
    	iter = headB;
    	while(iter != nullptr){
    		auto found = set.find(iter);
    		if(found != set.end()){
    			ret = *found;
    			break;
    		}
    		iter = iter->next;
    	}
    	return ret;
	}
};

int main()
{
	Solution sol;
	
	ListNode n1(0), n2(9), n3(1), n4(3), n5(2), n6(4);
	ListNode *head1 = &n1, *head2 = &n4;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n5;
	n4.next = &n5;
	n5.next = &n6;
	cout << sol.getIntersectionNode(head1, head2)->val << '\n';
	return 0;
}