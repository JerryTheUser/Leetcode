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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> rets;
        if(!root) return rets;
        
        queue<Node*> que;
        que.push(root);
        Node* node;
       
        while(!que.empty()){
            vector<int> ret;
            int size = que.size();
            for(int i=0 ; i<size ; ++i){
                node = que.front();
                que.pop();
                ret.push_back(node->val);
                for(auto& child : node->children)
                    que.push(child);
            }
            rets.push_back(ret);
        }
        return rets;
    }
};