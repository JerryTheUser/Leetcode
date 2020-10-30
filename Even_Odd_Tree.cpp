#include <iostream>
#include <vector>
#include <queue>
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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        bool ret = true, odd = true;
        int tmp, size;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty() && ret){
            size = que.size();
            for(int i=0 ; i<size ; ++i){
                TreeNode* node = que.front();
                que.pop();
                if(odd && node->val&1 || !odd && !(node->val&1)){
                    if(i == 0) tmp = node->val;
                    else {
                        if(odd && node->val > tmp || !odd && node->val < tmp)
                            tmp = node->val;
                        else {
                            ret = false;
                            break;
                        }
                    }
                }
                else{
                    ret = false;
                    break;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            odd = !odd;
        }
        return ret;
    }
};