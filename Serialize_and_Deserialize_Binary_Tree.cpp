#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <limits>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return string();
        queue<TreeNode*> que;
        que.push(root);
        
        string ret;
        ret += to_string(root->val);

        while(!que.empty()){
            TreeNode *tmp = que.front();
            que.pop();
            if(tmp->left){
                ret += ","+to_string(tmp->left->val);
                que.push(tmp->left);
            }else ret+=",null";
            if(tmp->right){
                ret += ","+to_string(tmp->right->val);
                que.push(tmp->right);
            }else ret+=",null";
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        
        vector<TreeNode*> vec;
        char *c_str = new char[data.size()+1];
        strcpy(c_str, data.c_str());
        
        char *token = strtok(c_str, ",");
        while(token != nullptr){
            if(!strcmp(token, "null"))
                vec.push_back(nullptr);
            else
                vec.push_back(new TreeNode(atoi(token)));
            token = strtok(nullptr, ",");
        }
        
        queue<TreeNode*> que;
        TreeNode *root = vec[0];
        que.push(root);
        int index = 0;

        while(!que.empty() && index < vec.size()){
            TreeNode *tmp = que.front();
            que.pop();

            TreeNode* left = ++index < vec.size() ? vec[index] : nullptr;
            TreeNode* right = ++index < vec.size() ? vec[index] : nullptr;

            if(left != nullptr){
                tmp->left  = left;
                que.push(left);
            }
            if(right != nullptr){
                tmp->right = right;
                que.push(right);
            }
        }
        return root;
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
    Codec cod;
    string input("1,2,3,null,null,4,5,null,6,7,8");
    TreeNode* result = cod.deserialize(input);
    print_tree(result);
    string origin = cod.serialize(result);
    cout << origin << '\n';
    return 0;
}