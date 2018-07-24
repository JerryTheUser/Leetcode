#include <iostream>
using std::cout;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_tree(TreeNode *head){
    if(head == nullptr)return;
    else{
        cout << head->val << '\n';
        print_tree(head->left);
        print_tree(head->right);
    }
}

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr && t2==nullptr)return nullptr;
        if(t1==nullptr){
            TreeNode *tmp = new TreeNode(t2->val);
            tmp -> left = mergeTrees(nullptr,t2->left);
            tmp -> right = mergeTrees(nullptr,t2->right);
            return tmp;
        }
        else if(t2==nullptr){
            TreeNode *tmp = new TreeNode(t1->val);
            tmp -> left = mergeTrees(t1->left,nullptr);
            tmp -> right = mergeTrees(t1->right,nullptr);
            return tmp;
        }
        else{
            TreeNode *tmp = new TreeNode(t1->val+t2->val);
            tmp -> left = mergeTrees(t1->left,t2->left);
            tmp -> right = mergeTrees(t1->right,t2->right);
            return tmp;
        } 
    }

    TreeNode* mergeTrees_opt(TreeNode* t1, TreeNode* t2) {
		if (t2 == NULL) return t1;
		if (t1 == NULL) t1 = new TreeNode(t2->val);
		else t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};


int main(){
    TreeNode *h1;
    TreeNode n1(1);
    TreeNode n3(3);
    TreeNode n2(2);
    TreeNode n5(5);
    h1 = &n1;
    n1.left = &n3;
    n1.right = &n2;
    n3.left = &n5;

    TreeNode *h2;
    TreeNode d2(2);
    TreeNode d1(1);
    TreeNode d3(3);
    TreeNode d4(4);
    TreeNode d7(7);
    h2 = &d2;
    d2.left = &d1;
    d2.right = &d3;
    d1.right = &d4;
    d3.right = &d7;

    Solution sol;
    TreeNode *Ta = sol.mergeTrees(h1,h2);
    print_tree(Ta);
    return 0;
}
