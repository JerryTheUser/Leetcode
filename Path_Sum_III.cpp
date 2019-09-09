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
    int dfs(TreeNode *root, int sum){
    	int ret = 0;
    	if(root == 0)
    		return 0;
    	if(root->val == sum)
    		++ret;
    	ret += dfs(root->left, sum - root->val);
    	ret += dfs(root->right, sum - root->val);
    	return ret;
    }

    int pathSum(TreeNode* root, int sum) {
    	if(root == nullptr)
    		return 0;
    	return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
};

int main()
{
	Solution sol;
	TreeNode n1(10), n2(5), n3(-3), n4(3), n5(2), n6(11), n7(3), n8(-2), n9(1);
	TreeNode *head = &n1;
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.right = &n6;
	n4.left = &n7;
	n4.right = &n8;
	n5.right = &n9;
	cout << sol.pathSum(head, 8) << '\n';
	return 0;
}