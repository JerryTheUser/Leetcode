#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
/*
class Solution {
public:
    TreeNode* constructSubTree(vector<int>& preorder, int left, int right){
        if(left > right)
            return nullptr;
        else{
            TreeNode* ret = new TreeNode(preorder[left]);
            int find = left;
            for(int i=left ; i<=right ; ++i){
                if(preorder[i] > preorder[left]){
                    find = i;
                    break;
                }
            };
            if(find == left){
                ret->right = nullptr;
                ret->left = constructSubTree(preorder, ++left, right);
            }
            else{
                ret->right = constructSubTree(preorder, find, right);
                ret->left = constructSubTree(preorder, ++left, find-1);
            }; 
            return ret;
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
            return nullptr;
        else
            return constructSubTree(preorder, 0, preorder.size()-1);
        return nullptr;
    }
};
*/

class Solution {
public:
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
        if (i == A.size() || A[i] > bound)
            return nullptr;
        TreeNode* root = new TreeNode(A[i]);
        ++i;
        root->left = bstFromPreorder(A, root->val);
        root->right = bstFromPreorder(A, bound);
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

int main()
{
    Solution sol;
    vector<int> input{8,5,1,7,10,12},
                input2{1},
                input3{1, 2, 3, 4, 5, 6},
                input4{6, 6, 5, 4, 3, 2, 1}; 
    TreeNode* result = sol.bstFromPreorder(input4);
    print_tree(result);
    return 0;
}