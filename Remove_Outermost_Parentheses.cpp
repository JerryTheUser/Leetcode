#include <iostream>
#include <vector>
#include <string>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string removeOuterParentheses(string S) {
        int size = S.size();
        int begin = 0;
        int len = 0;
        int stack = 0;
        string ret = "";
        for(int i=0 ; i<size; ++i){
            if(S[i] == '(')
                ++stack;
            if(S[i] == ')')
                --stack;
            ++len;
            
            if(stack == 0){    
                ret.append(S, begin+1, len-2);
                len = 0;
                begin = i+1;
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    string S1 = "(()())(())(()(()))";
    string S2 = "()()";
    string S3 = "(()())(())";
    cout << sol.removeOuterParentheses(S3) << '\n';
}