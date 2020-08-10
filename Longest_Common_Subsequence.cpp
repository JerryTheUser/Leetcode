#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i=0 ; i<text1.size() ; ++i){
            for(int j=0 ; j<text2.size() ; ++j){  
                if(text1[i] == text2[j])
                    ++dp[i][j];
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main(){
    Solution sol;
    string text1("abcde");
    string text2("ace");
    cout << sol.longestCommonSubsequence(text1, text2) << '\n';
    return 0;
}