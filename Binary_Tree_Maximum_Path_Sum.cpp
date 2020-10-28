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
    int dfs(TreeNode* root, int& ret){
        if(!root) return 0;
        int left = dfs(root->left, ret);
        int right = dfs(root->right, ret);
        int tmp = max(root->val, root->val+max(left, right));
        int tmp2 = max(tmp, root->val+left+right);
        ret = max(ret, tmp2);
        return tmp;
    }
    
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        dfs(root, ret);
        return ret;
    }
};