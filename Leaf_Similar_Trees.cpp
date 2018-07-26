#include <iostream>
#include <vector>
using std::vector;
using std::cout;

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

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2;
        traversal(root1,r1);
        traversal(root2,r2);
        cout << std::boolalpha;
        return r1 == r2;
    }

    void traversal(TreeNode* head,vector<int>& vec){
        if(head == nullptr)return;
        if(!head->left && !head->right)vec.push_back(head->val);
        traversal(head->left,vec);
        traversal(head->right,vec);
        return;
    }
};

int main(){
    TreeNode *root1;
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n8(8);
    TreeNode n9(9);
    root1 = &n3;
    n3.left = &n5;
    n3.right = &n1;
    n5.left = &n6;
    n5.right = &n2;
    n2.left = &n7;
    n2.right = &n4;
    n1.left = &n9;
    n1.right = &n8;

    TreeNode *root2;
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    TreeNode t7(7);
    TreeNode t8(8);
    TreeNode t9(9);
    root2 = &t1;
    t1.left = &t5;
    t1.right = &t3;
    t5.left = &t6;
    t5.right = &t7;
    t3.left = &t2;
    t3.right = &t8;
    t2.left = &t4;
    t2.right = &t9;


    //print_tree(root2);
    Solution sol;
    cout << sol.leafSimilar(root1,root2) << '\n';
    return 0;
}

