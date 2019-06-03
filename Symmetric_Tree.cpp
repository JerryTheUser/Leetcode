#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool checkChild(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
            return true;
        else if(left == nullptr || right == nullptr)
            return false;
        else{
            if(left->val == right->val)
                return checkChild(left->left, right->right) && 
                    checkChild(left->right, right->left);
            else
                return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root != nullptr)
            return checkChild(root->left, root->right);
        return true;
    }
};

int main(){
    TreeNode *h;
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    TreeNode n4(3);
    TreeNode n5(4);
    TreeNode n6(4);
    TreeNode n7(3);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    Solution sol;
    cout << sol.isSymmetric(h) << '\n';
    return 0;
}