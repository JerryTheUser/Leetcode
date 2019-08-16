#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class MinStack {
public:
    MinStack() {
        count = 0;
        head = new ListNode(INT_MAX);
    }
    
    void push(int x) {
        ListNode *node = new ListNode(x);
        if(x <= head->val)
            head->val = x;
        node -> next = head->next;
        head->next = node;
        ++count;
    }
    
    void pop() {
        if(count > 0){
            --count;
            ListNode *node = head->next;
            int min = INT_MAX;

            if(node->val == head->val){
                if(count > 0){
                    ListNode *tmp = node->next;
                    while(tmp != nullptr){
                        if(tmp->val < min)
                            min = tmp->val;
                        tmp = tmp->next;
                    }
                }
                head->val = min;
            }
            head->next = node->next;
            delete node;
        }
    }
    
    int top() {
        return head->next->val;
    }
    
    int getMin() {
        return head->val;
    }
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
 
    void printList(ListNode *head){
        ListNode *run = head;
        while(run != nullptr){
            cout << run->val  << ' ';
            run = run->next;
        }
        cout << '\n';
    }

    ListNode *head;
    int count;
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-1);

    cout << obj->getMin() << '\n';
    cout << obj->top() << '\n';
    obj->pop();
    cout << obj->getMin() << '\n';
    return 0;
}