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


class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == nullptr)
        	return nullptr;
        TreeNode *ret = root, *run = root, *tmp;
        int accumulator = 0;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()){
        	tmp = stk.top();
        	stk.pop();
        	while(tmp != nullptr){
        		stk.push(tmp);
        		tmp = tmp->right;
        	}
        	tmp = stk.top();
        	stk.pop();
        	accumulator += tmp->val;
        	tmp->val = accumulator;
        	if(tmp->left != nullptr)
        		stk.push(tmp->left);
        }
    	return ret;
    }
};

void print_tree(TreeNode *head){
    if(head == nullptr)return;
    else{
        cout << head->val << '\n';
        print_tree(head->left);
        print_tree(head->right);
    }
}

int main(){
    TreeNode *h;
    TreeNode n1(4), n2(1), n3(6), n4(0), n5(2), n6(5), n7(7), n8(3), n9(8);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    n5.right = &n8;
    n7.right = &n9;

    Solution sol;
    TreeNode *result = sol.bstToGst(h);
    print_tree(result);
    return 0;
}