#include <iostream>
#include <utility>
#include <stack>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void removeNode(pair<TreeNode*, TreeNode*> pr){
        if(pr.first->left == pr.second)
            pr.first->left = nullptr;
        else
            pr.first->right = nullptr;
    }
    
    void addToStack(stack<pair<TreeNode*, TreeNode*>>& stk, TreeNode* input){
        if(input != nullptr){
            if(input->left != nullptr){
                stk.push(make_pair(input, input->left));
                addToStack(stk, input->left);
            }
            if(input->right != nullptr){
                stk.push(make_pair(input, input->right));
                addToStack(stk, input->right);
            }
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<pair<TreeNode*, TreeNode*>> stk;
        addToStack(stk, root);
        while(!stk.empty()){
            pair<TreeNode*, TreeNode*> tmp = stk.top();
            stk.pop();
            if(tmp.second->left == nullptr && tmp.second->right == nullptr && tmp.second->val == target)
                removeNode(tmp);
        }
        if(root->left == nullptr && root->right == nullptr && root->val == target)
            root = nullptr;
        return root;
    }
};

/*
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root,target);
    }
    
    TreeNode* dfs(TreeNode* root, int target){
        if(root == nullptr) return nullptr;
    
        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);

        if(root->left == nullptr && root->right == nullptr && root->val == target)
            root = NULL;
    
        return root;
    }
};
*/

void print_tree(TreeNode *head){
    if(head == nullptr)return;
    else{
        cout << head->val << '\n';
        print_tree(head->left);
        print_tree(head->right);
    }
}

int main(){
    Solution sol;
    TreeNode *head;
    TreeNode n1(1), n2(2), n3(3), n4(2), n5(2), n6(4);
    head = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    head = sol.removeLeafNodes(head, 2);
    print_tree(head);
    return 0;
}