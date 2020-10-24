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
    vector<TreeNode*> constructByRange(int left, int right){
        if(left > right) return vector<TreeNode*>{nullptr};
        if(left == right){
            TreeNode* node = new TreeNode(left);
            return vector<TreeNode*>{node};
        }
        vector<TreeNode*> ret;
        for(int i=left ; i<=right ; ++i){
            for(auto& leftTree : constructByRange(left, i-1)){
                for(auto& rightTree : constructByRange(i+1, right)){
                    TreeNode* node = new TreeNode(i);
                    node -> left = leftTree;
                    node -> right = rightTree;
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return constructByRange(1, n);
    }
};