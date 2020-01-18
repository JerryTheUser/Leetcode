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
    int sumEvenGrandparent(TreeNode* root) {
        int ret = 0;
        if(root == nullptr)
            return 0;
        else {
            if(!(root->val & 1)){
                if(root->left != nullptr){
                    if(root->left->left != nullptr)
                        ret += root->left->left->val;
                    if(root->left->right != nullptr)
                        ret += root->left->right->val;
                } 
                if(root->right != nullptr){
                    if(root->right->left != nullptr)
                        ret += root->right->left->val;
                    if(root->right->right != nullptr)
                        ret += root->right->right->val;
                }
            }
            ret += sumEvenGrandparent(root->left);
            ret += sumEvenGrandparent(root->right);
        }
        return ret;
    }
};
*/

class Solution {
public:
    int getValue(TreeNode* root){
        int ret = 0;
        if(root->left != nullptr){
            if(root->left->left != nullptr)
                ret += root->left->left->val;
            if(root->left->right != nullptr)
                ret += root->left->right->val;
        } 
        if(root->right != nullptr){
            if(root->right->left != nullptr)
                ret += root->right->left->val;
            if(root->right->right != nullptr)
                ret += root->right->right->val;
        }
        return ret;
    }
    void calculateSum(TreeNode* root, int& sum){
        if(root){
            if(!(root->val & 1))
                sum += getValue(root);
            calculateSum(root->left, sum);
            calculateSum(root->right, sum);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ret = 0;
        calculateSum(root, ret);
        return ret;
    }
};

int main(){
    Solution sol;
    TreeNode n1(6), n2(7), n3(8), n4(2), n5(7), n6(1), n7(3), n8(9), n9(1), n10(4), n11(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    n4.left = &n8;
    n5.left = &n9;
    n5.right = &n10;
    n7.right = &n11;

    cout << sol.sumEvenGrandparent(&n1) << '\n';
    return 0;
}