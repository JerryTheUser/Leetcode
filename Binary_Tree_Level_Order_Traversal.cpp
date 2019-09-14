#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void nextLevel(vector<vector<int>>& ret, vector<TreeNode*>& last){
        if(last.size() == 0)
            return;
        else{
            vector<int> element;
            vector<TreeNode*> next;
            for(int i=0 ; i<last.size() ; ++i){
                element.push_back(last[i]->val);
                if(last[i]->left != nullptr)
                    next.push_back(last[i]->left);
                if(last[i]->right != nullptr)
                    next.push_back(last[i]->right);
            }
            ret.push_back(element);
            nextLevel(ret, next);
            return;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
        vector<TreeNode*> top{root};
        nextLevel(ret, top);
        return ret;
    }
};

int main(){
    TreeNode *h;
    TreeNode n1(3), n2(9), n3(20), n4(15), n5(7);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(h);
    for(auto&& i : result){
        for(auto&& j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}