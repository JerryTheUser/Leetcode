#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
private:
    TreeNode* head;
    unordered_set<int> elements;
public:
    FindElements(TreeNode* root) {
        head = root;
        stack<TreeNode*> stk;
        if(root){
            root->val = 0;
            stk.push(root);
            elements.insert(root->val);
            while(!stk.empty()){
                TreeNode* tmp = stk.top();
                stk.pop();
                elements.insert(tmp->val);
                if(tmp->right){
                    tmp->right->val = 2 * tmp->val + 2;
                    stk.push(tmp->right);
                }
                if(tmp->left){
                    tmp->left->val = 2 * tmp->val + 1;
                    stk.push(tmp->left);
                }
            }
        }
    }
    
    bool find(int target) {
        auto e = elements.find(target);
        return e != elements.end() ? true : false;
    }
};

void print_tree(TreeNode* head){
    if(head == nullptr)
        cout << "null ";
    else{
        cout << head->val << ' ';
        print_tree(head->left);
        print_tree(head->right);
    }
}

int main(){
    TreeNode n0(-1), n2(-1), n5(-1), n11(-1);
    n0.right = &n2;
    n2.left = &n5;
    n5.left = &n11;
    TreeNode* root = &n0;

    print_tree(root);
    cout << '\n';
    FindElements* obj = new FindElements(root);
    print_tree(root);
    cout << '\n';
    cout << boolalpha << obj->find(0) << '\n';
    cout << boolalpha << obj->find(2) << '\n';
    cout << boolalpha << obj->find(3) << '\n';
    cout << boolalpha << obj->find(5) << '\n';
    cout << boolalpha << obj->find(10) << '\n';
    cout << boolalpha << obj->find(11) << '\n';
    return 0;
}