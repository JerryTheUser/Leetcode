#include <iostream>
#include <queue>
#include <utility>
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
    int deepestLeavesSum(TreeNode* root) {
        int ret = 0;
        queue<pair<int, TreeNode*>> que;
        pair<int , TreeNode*> tmp;
        que.push(make_pair(0, root));

        while(!que.empty()){
            tmp = que.front();
            que.pop();

            if(tmp.second -> left != nullptr)
                que.push(make_pair(tmp.first+1, tmp.second->left));
            if(tmp.second -> right != nullptr)
                que.push(make_pair(tmp.first+1, tmp.second->right));
        
            if(!que.empty()){
                if(que.front().first > tmp.first)
                    ret = que.front().second->val;
                else
                    ret += que.front().second->val;
            }
        }
        return ret;
    }
};
*/

class Solution {
public:
    vector<int> count;
    void dfs(TreeNode* root, int depth) {
        if(root != NULL) {
            while(count.size() <= depth)
                count.push_back(0);
            count[depth] += root->val;
        }
        if(root->left != NULL) dfs(root->left, depth+1);
        if(root->right != NULL) dfs(root->right, depth+1);
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return count[count.size()-1];
    }
};

int main(){
    Solution sol;
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n6.right = &n8;
    cout << sol.deepestLeavesSum(&n1) << '\n';
    return 0;
}