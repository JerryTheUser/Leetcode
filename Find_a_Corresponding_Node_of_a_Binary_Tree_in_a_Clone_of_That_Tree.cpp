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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ret = nullptr;
		if(original == nullptr || cloned == nullptr)
			return nullptr;
		else{
			if(original == target){
				ret = cloned;
				return ret;
			}
			if(ret == nullptr)
				ret = getTargetCopy(original->left, cloned->left, target);
			if(ret == nullptr)
				ret = getTargetCopy(original->right, cloned->right, target);
		}
		return ret;
    }
};

int main(){
	Solution sol;
	TreeNode* head, *head2;
	TreeNode n1(7), n2(4), n3(3), n4(6), n5(19);
	head = &n1;
	n1.left = &n2;
	n1.right = &n3;
	n3.left = &n4;
	n3.right = &n5;

	TreeNode m1(7), m2(4), m3(3), m4(6), m5(19);
	head2 = &m1;
	m1.left = &m2;
	m1.right = &m3;
	m3.left = &m4;
	m3.right = &m5;

	cout << sol.getTargetCopy(head, head2, &n3)->val << '\n';

	return 0;
}
