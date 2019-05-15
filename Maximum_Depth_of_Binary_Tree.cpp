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
    int maxDepth(TreeNode* root) {
        if(root != nullptr){
            return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
        }
        else
            return 0;
    }
};

int main(){
    TreeNode *h;
    TreeNode n1(3);
    TreeNode n2(9);
    TreeNode n3(20);
    TreeNode n6(15);
    TreeNode n7(7);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n6;
    n3.right = &n7;

    Solution sol;
    cout << sol.maxDepth(h) << '\n';
    return 0;
}