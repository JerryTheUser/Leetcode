#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> stk;
        int ret = 0;
        for(int i=0 ; i<s.size() ; ++i){
            if(stk.empty())
                stk.push(s[i]);
            else{
                char tmp = stk.top();
                if(s[i] != tmp){
                    stk.pop();
                    if(stk.empty())
                        ++ret;
                }
                else
                    stk.push(s[i]);       
            }
        }
        return ret;
    }
};
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int ret = 0;
        int balance = 0;
        for(int i=0 ; i<s.size() ; ++i){
            if(s[i] == 'L')
                balance -= 1;
            else
                balance += 1;
            if(balance == 0)
                ++ret;
        }
        return ret;
    }
};


int main(){
    Solution sol;
    string input("RLLLLRRRLR"), input2("LLLLRRRR"), input3("RLRRRLLRLL"), input4("RLRRLLRLRL");
    cout << sol.balancedStringSplit(input) << '\n';
    cout << sol.balancedStringSplit(input2) << '\n';
    cout << sol.balancedStringSplit(input3) << '\n';
    cout << sol.balancedStringSplit(input4) << '\n';
    return 0;
}