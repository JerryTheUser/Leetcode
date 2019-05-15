#include <iostream>
#include <vector>
#include <algorithm>
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr)
            return 0;
        else{
            if(root->val < L)
                return rangeSumBST(root->right, L, R);
            else if(root->val > R)
                return rangeSumBST(root->left, L, R);
            else
                 return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
    }
};

int main(){
    TreeNode *h;
    TreeNode n1(10);
    TreeNode n2(5);
    TreeNode n3(15);
    TreeNode n4(3);
    TreeNode n5(7);
    TreeNode n6(13);
    TreeNode n7(18);
    TreeNode n8(1);
    TreeNode n10(6);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    n4.left = &n8;
    n5.right = &n10;

    Solution sol;
    cout << sol.rangeSumBST(h, 6, 10)<< '\n';
    return 0;
}