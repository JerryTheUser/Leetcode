#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i=0 ; i<row ; ++i){
            for(int j=0 ; j<col ; ++j){
                dp[i][j] = matrix[i][j] == '1' ? (j == 0 ? 1 : dp[i][j-1] + 1) : 0;
            }
        }
        int ret = 0;
        for(int i=0 ; i<row ; ++i){
            for(int j=0 ; j<col ; ++j){
                int tmp = INT_MAX;
                for(int k=i ; k<row ; ++k){
                    tmp = min(tmp, dp[k][j]);
                    if(tmp == 0) break;
                    ret = max(ret, tmp*(k-i+1));
                }
            }
        }
        return ret;
    }
};