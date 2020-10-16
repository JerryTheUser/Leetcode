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
    TreeNode* cur;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        root->left = nullptr;
        cur->right = root;
        cur = cur->right;
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ret = new TreeNode(0);
        cur = ret;
        inorder(root);
        return ret->right;
    }
};

/*
class Solution {
public:
    TreeNode* reBuildBST(vector<int>& record, int num){
        if(num == record.size()) return nullptr;
        TreeNode* head = new TreeNode(record[num]);
        head->right = reBuildBST(record, num+1);
        return head;
    }
    
    void recordVal(TreeNode* root, vector<int>& record){
        if(!root) return;
        recordVal(root->left, record);
        record.push_back(root->val);
        recordVal(root->right, record);
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        vector<int> record;
        recordVal(root, record);
        return reBuildBST(record, 0);
    }
};
*/