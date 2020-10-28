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
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT_MAX, INT_MIN);
    }
    
    bool isBST(TreeNode* root,long int max,long int min){
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        return isBST(root->left, root->val, min) && isBST(root->right, max, root->val);
    }
};

/*
class Solution {
public:
    int findSmallest(TreeNode* root) {
        while(root->left)
            root = root->left;
        return root->val;
    }
    
    int findLargest(TreeNode* root){
        while(root->right)
            root = root->right;
        return root->val;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool check = true;
        if(root->left && root->val <= findLargest(root->left)) check = false;
        if(root->right && root->val >= findSmallest(root->right)) check = false;
        return check && isValidBST(root->left) && isValidBST(root->right);
    }
};
*/