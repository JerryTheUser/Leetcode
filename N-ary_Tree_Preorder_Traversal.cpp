#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void traversal(vector<int>& ret, Node* root){
        if(root == nullptr) return; 
        else{
            ret.push_back(root->val);
            for(auto& child : root->children)
                traversal(ret, child);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ret;
        traversal(ret, root);
        return ret;
    }
};