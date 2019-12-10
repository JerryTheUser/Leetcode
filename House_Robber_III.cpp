#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void transform(TreeNode* root){
        if(root != nullptr){
            int odd = root->val, even = 0;
            if(root->left != nullptr){
                transform(root->left);
                even += root->left->val;
                if(root->left->left != nullptr)
                    odd += root->left->left->val;
                if(root->left->right != nullptr)
                    odd += root->left->right->val;
            }
            if(root->right != nullptr){
                transform(root->right);
                even += root->right->val;
                if(root->right->left != nullptr)
                    odd += root->right->left->val;
                if(root->right->right != nullptr)
                    odd += root->right->right->val;
            }
            root->val = max(odd, even);
        }
    }
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        transform(root);
        return root->val;
    }
};

void print_tree(TreeNode* head){
    if(head == nullptr)
        cout << "null ";
    else{
        cout << head->val << ' ';
        print_tree(head->left);
        print_tree(head->right);
    }
}

int main(){
    Solution sol;
    TreeNode n0(3), n1(4), n2(5), n3(1), n4(3), n6(1), n5(2);
    n0.left = &n1;
    n0.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    n2.left = &n5;
    n2.right = &n6;
    TreeNode *head = &n0;
    cout << sol.rob(head) << '\n';
    return 0;
}