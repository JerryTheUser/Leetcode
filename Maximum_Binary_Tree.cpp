#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::max_element;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);  
    }

    TreeNode* solve(vector<int>& nums,int begin,int end){
        if(begin > end)return nullptr;
        else{
            int index = begin;
            int max = nums[index];
            int i;
            for(i=begin ; i<=end ; ++i){
                if(nums[i] > max){
                    index = i;
                    max = nums[index];
                }   
            }
            TreeNode *head = new TreeNode(max);
            head -> left = solve(nums,begin,index-1);
            head -> right = solve(nums,index+1,end);
            return head;
        } 
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
    vector<int> input = { 5,6,7,3,2,4,9,11,23,16,13,28,1,2};
    Solution sol;
    TreeNode *Ta = sol.constructMaximumBinaryTree(input);
    print_tree(Ta);
    return 0; 
}
