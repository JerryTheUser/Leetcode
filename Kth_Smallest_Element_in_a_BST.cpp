#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(true){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            --k;
            if(k == 0) return root->val;
            root = root->right;
        }
        return 0;
    }
};

int main(){
    Solution sol;
    TreeNode *h;
    TreeNode n1(5), n2(3), n3(6), n4(2), n5(4), n6(1);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n4.left = &n6;
    
    cout << sol.kthSmallest(h, 1) << '\n';
    cout << sol.kthSmallest(h, 2) << '\n';
    cout << sol.kthSmallest(h, 3) << '\n';
    cout << sol.kthSmallest(h, 4) << '\n';
    cout << sol.kthSmallest(h, 5) << '\n';
    cout << sol.kthSmallest(h, 6) << '\n';
    return 0;
}