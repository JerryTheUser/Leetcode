#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_tree(TreeNode *head){
    if(head == nullptr)return;
    else{
        cout << head->val << '\n';
        print_tree(head->left);
        print_tree(head->right);
    }
}

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *insert = new TreeNode(val);
        if(root == nullptr)
            root = insert;
        else{
            TreeNode *run = root;
            TreeNode *pre = root;
            while(run != nullptr){
                pre = run;
                if(run->val >= val)
                    run = run->left;
                else
                    run = run->right;
            }
            if(pre->val >= val)
                pre->left = insert;
            else
                pre->right = insert;
        }
        return root;
    }
};

int main(){
    TreeNode *h;
    TreeNode n1(4);
    TreeNode n2(2);
    TreeNode n3(7);
    TreeNode n4(1);
    TreeNode n5(3);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;

    Solution sol;
    sol.insertIntoBST(h, 5);
    print_tree(h);
    return 0;
}