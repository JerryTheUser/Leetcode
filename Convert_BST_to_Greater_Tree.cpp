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
    int accumulator = 0;
    void calculateValue(TreeNode* node) {
        if(node == nullptr)
            return;
        else{
            calculateValue(node->right);
            node -> val += accumulator;
            accumulator = node -> val;
            calculateValue(node->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *ret = root;
        calculateValue(root);
        //root->val += accumulator;
        //calculateValue(root->left);
        return ret;
    }
};

void print_tree(TreeNode *head){
    if(head == nullptr)return;
    else{
        cout << head->val << '\n';
        print_tree(head->left);
        print_tree(head->right);
    }
}

int main()
{
    Solution sol;
    TreeNode *h, *res;
    TreeNode n1(8), n2(6), n3(10), n4(3), n5(7), n6(9), n7(11);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    res = sol.convertBST(h);
    print_tree(res);
    return 0;
}