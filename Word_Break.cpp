#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(auto& word : wordDict) dict.insert(word);
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i=0 ; i<s.size() ; ++i){
            for(int j=i ; j>=0 ; j--){
                string cur = s.substr(j, i-j+1);
                if(dict.find(cur) != dict.end())
                    dp[i+1] = dp[i+1] | dp[j]; 
                if(dp[i+1]) break;
            }
        }
            
        return dp[s.size()];
    }
};

int main(){
    Solution sol;
    vector<string> input {"apple", "pen"};
    string s("applepenapple");
    cout << boolalpha << sol.wordBreak(s, input) << '\n';
    return 0;
}
