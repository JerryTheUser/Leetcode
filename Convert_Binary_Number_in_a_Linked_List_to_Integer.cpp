#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
  
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        while(head != nullptr){
            ret = ret*2 + head->val;
            head = head->next;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    ListNode n0(0), n1(1), n2(0);
    n0.next = &n1;
    n1.next = &n2;
    ListNode* head = &n0;
    cout << sol.getDecimalValue(head) << '\n';
    return 0;
}