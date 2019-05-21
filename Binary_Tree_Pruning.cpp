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
    bool pruneCheck(TreeNode* root){
        if(root != nullptr){
            if(root->val == 0 && pruneCheck(root->left) && pruneCheck(root->right))
                return true;
            else
                return false;
        }
        return true;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(root != nullptr){
            if(pruneCheck(root->left))
                root->left = nullptr;
            else
                root->left = pruneTree(root->left);
            if(pruneCheck(root->right))
                root->right = nullptr;
            else
                root->right = pruneTree(root->right);
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
    TreeNode n1(1);
    TreeNode n2(0);
    TreeNode n3(1);
    TreeNode n4(0);
    TreeNode n5(0);
    TreeNode n6(0);
    TreeNode n7(1);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    Solution sol;
    //print_tree(h);
    print_tree(sol.pruneTree(h));
    return 0;
}