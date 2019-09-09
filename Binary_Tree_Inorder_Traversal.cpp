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

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode *handler;
        stack<TreeNode*> nodeStack;
        if(root != nullptr){
        	nodeStack.push(root);
        	while(!nodeStack.empty()){
        		handler = nodeStack.top();
        		nodeStack.pop();
        		ret.push_back(handler->val);
        		if(handler->right != nullptr)
        			nodeStack.push(handler->right);
        		if(handler->left != nullptr)
        			nodeStack.push(handler->left);
        	}
        }
        return ret;
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ret;
        TreeNode *current = root;
        stack<TreeNode*> nodeStack;
        if(root != nullptr){
    		while(!nodeStack.empty() || current != nullptr){
    			while(current != nullptr && current->left != nullptr){
    				nodeStack.push(current);
    				current = current->left;
    			}
    			if(current == nullptr){
    				current = nodeStack.top();
    				nodeStack.pop();
    			}
    			ret.push_back(current->val);
    			current = current->right;
    		}
        }
        return ret;
    }
};

int main()
{
	TreeNode *h;
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    h = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    Solution sol;
    vector<int> result = sol.inorderTraversal(h);
    for(auto&& i : result)
    	cout << i << ' ';
    cout << '\n';
    return 0;
}