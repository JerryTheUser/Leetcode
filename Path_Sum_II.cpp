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
    vector<vector<int>> ret;
    void dfs(TreeNode* root, int sum, vector<int>& ref){
        if(root == nullptr)
            return;
        else{
            ref.push_back(root->val);
            if(!root->left && !root->right && sum == root->val)
                ret.push_back(ref);
            dfs(root->left, sum-root->val, ref);
            dfs(root->right, sum-root->val, ref);
            ref.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return ret;       
        vector<int> ref;
        dfs(root, sum, ref);
        return ret;
    }
};