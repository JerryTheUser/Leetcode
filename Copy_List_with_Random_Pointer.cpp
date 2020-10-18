#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> mapping;
        Node *cur = head;
        while(cur){
            Node* tmp = new Node(cur->val);
            mapping[cur] = tmp;
            cur = cur->next;
        }
        cur = head;
        while(cur){
            mapping[cur]->next = mapping[cur->next];
            mapping[cur]->random = mapping[cur->random];
            cur = cur->next;
        }
        return mapping[head];
    }
};