#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<vector<TreeNode*>> dp(N+2);
        dp[0] = {};
        dp[1] = {new TreeNode(0)};
        for(int index=3 ; index<=N ; index+=2){
            for(int i=1 ; i<index-1 ; i+=2){
                vector<TreeNode*> left = dp[i];
                vector<TreeNode*> right = dp[index - i - 1];
                for(int l=0 ; l<left.size() ; ++l){
                    for(int r=0 ; r<right.size() ; ++r){
                        TreeNode *root = new TreeNode(0);
                        root->left = left[l];
                        root->right = right[r];
                        dp[index].push_back(root);
                    }
                }
            }
        }    
        return dp[N];
    }
};

void print_tree(TreeNode* head){
    if(head == nullptr)
        cout << "null ";
    else{
        cout << head->val << ' ';
        print_tree(head->left);
        print_tree(head->right);
    }
}

int main(){
    Solution sol;
    vector<TreeNode*> result = sol.allPossibleFBT(7);
    for(auto& i : result){
        print_tree(i);
        cout << '\n';
    }
    return 0;
}