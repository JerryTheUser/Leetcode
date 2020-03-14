#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/*
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        TreeNode *iter = nullptr, *tmp;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            tmp = stk.top();
            stk.pop();
            if(iter)
                iter->right = tmp; 
            if(tmp->right != nullptr)
                    stk.push(tmp->right);
            while(tmp->left != nullptr){   
                tmp->right = tmp->left;
                tmp->left = nullptr;
                tmp = tmp->right;
                if(tmp->right != nullptr)
                    stk.push(tmp->right);
            }
            iter = tmp;
        }
        return;
    }
};
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* tmp = root->right;
    
        root->right = root->left;
        root->left = nullptr;
        while(root->right != nullptr)
            root = root->right;
        root->right = tmp;
    }
};

int main(){
    Solution sol;
    TreeNode* head;
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
	
    head = &n1;
	n1.left = &n2;
	n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
	n5.right = &n6;
    
    sol.flatten(head);    
    return 0;
}