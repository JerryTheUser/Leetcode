#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ret;

    void DFS(TreeNode* root, int cur){
        if(!root) return;

        cur <<= 1; 
        cur |= root->val;

        if(!root->left && !root->right){
            ret += cur;
            return;
        }

        DFS(root->left, cur);
        DFS(root->right, cur);
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        ret = 0;
        DFS(root, 0);
        return ret;
    }
};