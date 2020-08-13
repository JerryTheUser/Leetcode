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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;
        else if(left != nullptr) return left;
        else return right;
    }
};

/*
class Solution {
public:
    bool findNode(TreeNode* root, TreeNode* p){
        if(root == nullptr) return false;
        else if(root == p) return true;
        else return findNode(root->left, p) || findNode(root->right, p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        else if(root == p) return p;
        else if(root == q) return q;
        else{
            if(findNode(root->left, p) && findNode(root->left, q))
                return lowestCommonAncestor(root->left, p, q);
            else if(findNode(root->right, p) && findNode(root->right, q))
                return lowestCommonAncestor(root->right, p, q);
            else
                return root;
        }
    }
};
*/