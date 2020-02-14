#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int ret = 0;
        int count[26] = {0};
        for(auto& i : s)
            ++count[i - 'a'];
        for(auto& j : t){
            if(count[j - 'a'] != 0)
                --count[j - 'a'];
        }
        for(int i=0 ; i<26 ; ++i)
            ret += count[i];
        return ret;
    }
};

int main(){
    Solution sol;
    string s("anagram"), t("mangaar");
    string s2("leetcode"), t2("practice");
    cout << sol.minSteps(s, t) << '\n';
    cout << sol.minSteps(s2, t2) << '\n';
    return 0;
}