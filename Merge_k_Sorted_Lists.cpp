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
    ListNode* merge(ListNode* list1,ListNode* list2){
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1->val < list2->val){
            list1->next = merge(list1->next, list2);
            return list1;
        }
        else{
            list2->next = merge(list2->next, list1);
            return list2;
        }

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        int remain = lists.size()-1;

        while(remain != 0){
            int i=0, j=remain;
            while(i<j){
                lists[i] = merge(lists[i], lists[j]);
                ++i; --j;
            }
            if(i>=j)remain=j;
        }

        return lists[0];
    }
};

/*
class Solution {
public:
    ListNode* mergeTwoLosts(ListNode* list1, ListNode* list2){
        ListNode *ret = nullptr, *iter = ret;

        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
        else{
            while(list1 != nullptr && list2 != nullptr){
                if(list1->val < list2->val){
                    if(!ret){
                        ret = list1;
                        iter = ret;
                    }
                    else{
                        iter->next = list1;
                        iter = iter->next;
                    }
                    list1 = list1->next;
                }   
                else{
                    if(!ret){
                        ret = list2;
                        iter = ret;
                    }
                    else{
                        iter->next = list2;
                        iter = iter->next;
                    }
                    list2 = list2->next;
                } 
            }
            
            if(list1 != nullptr)
                iter->next = list1;
            else if(list2 != nullptr)
                iter->next = list2;
            else;
        }
        return ret;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;

        for(int i=1 ; i<lists.size() ; ++i)
            lists[0] = mergeTwoLosts(lists[0], lists[i]);
        
        return lists[0];
    }
};
*/

int main(){
    Solution sol;
    ListNode i1(1), i2(4), i3(5); i1.next = &i2, i2.next = &i3;
    ListNode j1(1), j2(3), j3(4); j1.next = &j2, j2.next = &j3;
    ListNode k1(2), k2(6); k1.next = &k2;

    vector<ListNode*> input {&i1, &j1, &k1};

    ListNode* output = sol.mergeKLists(input);
    
    while(output != nullptr){
        cout << output->val << ' ';
        output = output->next;
    }
    cout << '\n';
    return 0;
}