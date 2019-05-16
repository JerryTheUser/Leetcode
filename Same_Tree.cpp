#include <iostream>
#include <vector>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        else if( p != nullptr && q != nullptr) {
            if(p -> val == q->val)
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            else
                return false;
        }
        else
            return false;
    }
};

int main(){
    TreeNode *h1;
    TreeNode l1(3);
    TreeNode l2(9);
    TreeNode l3(20);
    TreeNode l6(15);
    TreeNode l7(7);
    h1 = &l1;
    l1.left = &l2;
    l1.right = &l3;
    l3.left = &l6;
    l3.right = &l7;

    TreeNode *h2;
    TreeNode r1(3);
    TreeNode r2(9);
    TreeNode r3(20);
    TreeNode r6(15);
    TreeNode r7(7);
    h2 = &r1;
    r1.left = &r2;
    r1.right = &r3;
    r3.left = &r6;
    r3.right = &r7;

    Solution sol;
    cout << sol.isSameTree(h1, h2) << '\n';
    return 0;
}