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
    TreeNode* buildTree(vector<int>& list, int left, int right){
        int mid = (right + left) / 2;
        TreeNode *root = new TreeNode(list[mid]);
        if(left < mid) root->left = buildTree(list, left, mid-1);
        if(mid < right) root->right = buildTree(list, mid+1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return nullptr;
        else
            return buildTree(nums, 0, size-1);
        return nullptr;
    }
    /*TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        else if(nums.size() == 1){
            TreeNode *ret = new TreeNode(nums[0]);
            return ret;
        }
        else{
            int mid = nums.size() / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            vector<int> L(nums.begin(), nums.begin()+mid);
            vector<int> R(nums.begin()+mid+1, nums.end());
            root -> left = sortedArrayToBST(L);
            root -> right = sortedArrayToBST(R);
            return root;
        }
        return nullptr;
    }*/
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
    vector<int> A{-10,-3,0,5,9};
    Solution sol;
    print_tree(sol.sortedArrayToBST(A));
    return 0;
}