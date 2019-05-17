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
    TreeNode* invertTree(TreeNode* root) {
        if(root != nullptr){
            TreeNode *tmp = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(tmp);
        }
        return root;
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
    print_tree(h);
    print_tree(sol.invertTree(h));
    return 0;
}