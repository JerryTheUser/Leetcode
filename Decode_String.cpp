#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ret;
        stack<int> times;
        stack<char> strs;
        int tmp = 0, time = 0;

        for(int i=0 ; i<s.size() ; ++i){
            if(s[i] >= 48 && s[i] < 58){
                tmp *= 10;
                tmp += (s[i] - 48);
            }
            else if(s[i] == '['){
                times.push(tmp);
                tmp = 0;
                strs.push('[');
            }
            else if(s[i] == ']'){
                time = times.top();
                times.pop();
                string str;
                string duplicate;
                char item = strs.top();
                strs.pop();
                while(item != '['){
                    str += item;
                    item = strs.top();
                    strs.pop();
                }
                while(time > 0){
                    duplicate += str;
                    --time;
                }
                for(int i=duplicate.size()-1 ; i>=0 ; --i)
                    strs.push(duplicate[i]);
            }
            else{
                strs.push(s[i]);
            }
        }
        while(!strs.empty()){
            ret += strs.top();
            strs.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(){
    Solution sol;
    string input("3[a2[c]]"), input2("3[a]2[bc]"), input3("2[abc]3[cd]ef");
    cout << sol.decodeString(input) << '\n';
    cout << sol.decodeString(input2) << '\n';
    cout << sol.decodeString(input3) << '\n';
    return 0;
}