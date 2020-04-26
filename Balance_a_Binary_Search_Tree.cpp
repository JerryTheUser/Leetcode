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
    void recordBST(vector<TreeNode*>& record, TreeNode* root){
        if(root == nullptr)
            return;
        else{
            recordBST(record, root->left);
            record.push_back(root);
            recordBST(record, root->right);
        }
        return;
    }

    TreeNode* rebuildBST(vector<TreeNode*>& record, int i, int j){
        if(i > j)
            return nullptr;
        else{
            int mid = (i+j)/2;
            TreeNode *ret = new TreeNode(record[mid]->val);
            ret->left = i == mid ? nullptr : rebuildBST(record, i, mid-1);
            ret->right = j == mid ? nullptr : rebuildBST(record, mid+1, j);
            return ret;
        }
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> record;
        recordBST(record, root);
        return rebuildBST(record, 0, record.size()-1);
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
    Solution sol;
    TreeNode n1(1), n2(2), n3(3), n4(4);

    TreeNode *head = &n1, *result;
    n1.right = &n2;
    n2.right = &n3;
    n3.right = &n4;

    result = sol.balanceBST(head);
    print_tree(result);
    return 0;
}