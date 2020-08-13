#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;
        vector<int> dp {0};
        while(dp.size() <= n){
           int len = dp.size(), sqr = INT_MAX;
           for(int i=1 ; i*i<=len ; ++i)
               sqr = min(sqr, dp[len-i*i]+1);
           dp.emplace_back(sqr);
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    cout << sol.numSquares(5) << '\n';
    return 0;
}