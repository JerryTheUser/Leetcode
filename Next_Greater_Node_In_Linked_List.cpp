#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> stk;
        vector<int> arr;
        while(head != nullptr){
            arr.push_back(head->val);
            head = head->next;
        }
        vector<int> ret(arr);
        for(int i=0 ; i<ret.size() ; ++i){
            while(!stk.empty() && arr[stk.top()] < arr[i]){
                ret[stk.top()] = arr[i];
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            ret[stk.top()] = 0;
            stk.pop();
        }
        return ret;
    }
};