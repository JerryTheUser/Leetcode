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
    bool checkTree(TreeNode* root, int val){
        if(!root) return true;
        if(root->val != val) return false;
        return checkTree(root->left, val) && checkTree(root->right, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        return checkTree(root, root->val);
    }
};