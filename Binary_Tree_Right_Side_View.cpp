#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr)
            return ret;

        queue<TreeNode*> parent, child;
        TreeNode* tmp;
        parent.push(root);

        while(!parent.empty()){ 
            ret.push_back(parent.back()->val);
            while(!parent.empty()){
                tmp = parent.front();
                parent.pop();
                if(tmp->left != nullptr)
                    child.push(tmp->left);
                if(tmp->right != nullptr)
                    child.push(tmp->right);
            }
            swap(parent, child);
            while(!child.empty())
                child.pop();
        }
        return ret;
    }
};

int main(){
    Solution sol;
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n5;
    n3.right = &n4;
    n5.right = &n6;
    vector<int> result = sol.rightSideView(&n1);
    
    for(auto&& i : result)
        cout << i << ' ';
    cout << '\n';

    return 0;
}