#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        for(int i=0, j=0 ; i<pushed.size() ; ++i){
            stk.push(pushed[i]);
            while(!stk.empty() && j<popped.size() && popped[j] == stk.top()){
                stk.pop();
                ++j;
            }
        }
        return stk.empty();
    }
};


int main(){
    Solution sol;
    vector<int> pushed {1,2,3,4,5}, poped {4,3,5,1,2};
    cout << boolalpha << sol.validateStackSequences(pushed, poped) << '\n';
    return 0;
}