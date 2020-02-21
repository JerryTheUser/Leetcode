#include <iostream>
#include <vector>
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
    void putElementIntoVector(vector<int>& vec, TreeNode* root){
        if(root == nullptr)
            return;
        else{
            if(root->left == nullptr && root->right == nullptr)
                vec.push_back(root->val);
            else{
                putElementIntoVector(vec, root->left);
                vec.push_back(root->val);
                putElementIntoVector(vec, root->right);
            }
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        putElementIntoVector(vec1, root1);
        putElementIntoVector(vec2, root2);
        vector<int> ret(vec1.size()+vec2.size(), 0);
        merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), ret.begin());
        return ret;
    }
};

int main(){
    Solution sol;
    TreeNode n1(2), n2(1), n3(4), n4(1), n5(0), n6(3);
    n1.left = &n2;
    n1.right = &n3;
    n4.left = &n5;
    n4.right = &n6;
    TreeNode *tree1 = &n1, *tree2 = &n4;
    vector<int> result = sol.getAllElements(tree1, tree2);
    for(auto& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}