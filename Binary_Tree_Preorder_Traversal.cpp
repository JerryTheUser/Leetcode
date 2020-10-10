#include <iostream>
#include <vector>
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
    void traversal(vector<int>& ret, TreeNode* root){
        if(root == nullptr) return;
        else{
            ret.push_back(root->val);
            traversal(ret, root->left);
            traversal(ret, root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        traversal(ret, root);
        return ret;
    }
};