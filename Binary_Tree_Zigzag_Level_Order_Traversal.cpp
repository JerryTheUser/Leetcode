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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rets;
        if(!root) return rets;
        deque<TreeNode*> deq;
        deq.push_back(root);
        bool fromBack = true;
        TreeNode* node;
        
        while(!deq.empty()){
            int size = deq.size();
            vector<int> ret;        
            for(int i=0 ; i<size ; ++i){
                if(fromBack){
                    node = deq.back();
                    deq.pop_back();
                    if(node->left) deq.push_front(node->left);
                    if(node->right) deq.push_front(node->right);
                }
                
                else{
                    node = deq.front();
                    deq.pop_front();
                    if(node->right) deq.push_back(node->right);
                    if(node->left) deq.push_back(node->left);
                }
                ret.push_back(node->val);
            }
            fromBack = !fromBack;
            rets.push_back(ret);
        }
        return rets;
    }
};