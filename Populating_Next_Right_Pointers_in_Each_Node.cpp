#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
            
        queue<Node*> que;
        que.push(root);
        Node* tmp;
        int counter = 0, maxLevel = 1;

        while(!que.empty()){
            tmp = que.front();
            que.pop();
            ++counter;

            if(tmp->left != nullptr)
                que.push(tmp->left);
            if(tmp->right != nullptr)
                que.push(tmp->right);

            if(counter == maxLevel){
                tmp->next = nullptr;
                counter = 0;
                maxLevel *= 2;
            }
            else{
                if(!que.empty())
                    tmp->next = que.front();
            }
        }
        return root;
    }
};

void printTree(Node* root){
    stack<Node*> stk;
    Node* tmp;
    stk.push(root);
    while(!stk.empty()){
        tmp = stk.top();
        stk.pop();
        if(tmp->left != nullptr)
            stk.push(tmp->left);
        while(tmp != nullptr){
            cout << tmp->val << ' ';
            if(tmp->next == nullptr)
                cout << '#' << ' ';
            tmp = tmp->next;
        }
    }
    cout << '\n';
}

int main(){
    Solution sol;
    Node n7(7), 
         n6(6), 
         n5(5),
         n4(4),
         n3(3, &n6, &n7, nullptr), 
         n2(2, &n4, &n5, nullptr),
         n1(1, &n2, &n3, nullptr);
    /*
    Node n7(7), 
         n6(6, nullptr, nullptr, &n7), 
         n5(5, nullptr, nullptr, &n6),
         n4(4, nullptr, nullptr, &n5),
         n3(3, &n6, &n7, nullptr), 
         n2(2, &n4, &n5, &n3),
         n1(1, &n2, &n3, nullptr);
    */
    Node* result = sol.connect(&n1);
    printTree(result);
    return 0;
}