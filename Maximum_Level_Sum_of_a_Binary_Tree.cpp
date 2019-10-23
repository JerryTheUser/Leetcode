#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
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
    void fillTheRecord(unordered_map<int , int>& rec, TreeNode* root, int level){
        if(root == nullptr)
            return;
        auto iter = rec.find(level);
        if(iter == rec.end())
            rec[level] = root->val;
        else
            rec[level] += root->val;
        fillTheRecord(rec, root->left, level+1);
        fillTheRecord(rec, root->right, level+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        unordered_map<int , int> record;
        int idx = 1, val = INT_MIN;
        fillTheRecord(record, root, 1);
        for(auto& item : record){
            if(item.second > val){
                idx = item.first;
                val = item.second;
            }
        }
        return idx;
    }
};*/

class Solution {
public:
    vector<int> record;
    void fillTheRecord(TreeNode* root, int level){
        if(root == nullptr)
            return;
        if(level >= record.size())
            record.push_back(root->val);
        else
            record[level] += root->val;
        fillTheRecord(root->left, level+1);
        fillTheRecord(root->right, level+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        fillTheRecord(root, 0);

        int ret = 0;
        for(int i=1 ; i<record.size() ; ++i){
            if(record[i] > record[ret])
                ret = i;
        }
        return ret+1;
    }
};

int main(){
    Solution sol;
    TreeNode h1(1), h2(7), h3(0), h4(7), h5(-8);
    h1.left = &h2;
    h1.right = &h3;
    h2.left = &h4;
    h2.right = &h5;
    cout << sol.maxLevelSum(&h1) << '\n';
    return 0;
}