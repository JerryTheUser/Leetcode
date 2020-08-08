#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// Use unorder_map
class Solution {
public:
    unordered_map<int, int> idxMap;
    int preIndex = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            idxMap[inorder[i]] = i;
        return buildSubtree(preorder, 0, inorder.size());
    }
    
    TreeNode* buildSubtree(vector<int>& preorder, int il, int ir){
        if(il == ir) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIndex]);
        ++preIndex;
        int index = idxMap.at(root->val);
        root->left = buildSubtree(preorder, il, index);
        root->right = buildSubtree(preorder, index+1, ir);
        return root;
    }
};

/*
class Solution {
public:
    int findIndex(vector<int>& inorder, int target){
        for(int i=0 ; i<inorder.size() ; ++i)
            if(inorder[i] == target)
                return i;
        return 0;
    }
    
    TreeNode* createSubtree(vector<int>& preorder, vector<int>& inorder, int head, int il, int ir){
        if(il > ir) return nullptr;
        else if(il == ir){
            TreeNode* ret = new TreeNode(inorder[il]);
            return ret;
        }
        else{
            TreeNode* ret = new TreeNode(preorder[head]);
            int index = findIndex(inorder, preorder[head]);
            ret->left = createSubtree(preorder, inorder, head+1, il, index-1);
            ret->right = createSubtree(preorder, inorder, head+index-il+1, index+1, ir);
            return ret;
        }
        return nullptr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ret;
        ret = createSubtree(preorder, inorder, 0, 0, inorder.size()-1);
        return ret;
    }
};
*/

void print_tree(TreeNode *head){
    if(head == nullptr)return;
    else{
        cout << head->val << '\n';
        print_tree(head->left);
        print_tree(head->right);
    }
}

int main(){
    Solution sol;
    vector<int> preorder {3,9,20,15,7};
    vector<int> inorder {9,3,15,20,7};
    TreeNode* result = sol.buildTree(preorder, inorder);
    print_tree(result);
    return 0;
}