#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int size = prices.size();
        vector<int> rest(size, -1);
        vector<int> buy(size, -1);
        vector<int> sell(size, -1);
        rest[0] = 0, buy[0] = -prices[0], sell[0] = INT_MIN;
        for(int i=1 ; i<prices.size() ; ++i){
            rest[i] = max(rest[i-1], sell[i-1]);
            buy[i] = max(buy[i-1], rest[i-1]-prices[i]);
            sell[i] = buy[i-1] + prices[i];
        }
        return max(rest[size-1], sell[size-1]);
    }
};

/*
class Solution {
private:
    vector<int> dp;
public:
    int compareProfit(vector<int>& prices, int index){
        if(index >= prices.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int profit = 0;
        for(int i=index ; i<prices.size() ; ++i){
            profit = max(profit, prices[i]-prices[index]+compareProfit(prices, i+2));
        }
        profit = max(profit, compareProfit(prices, index+1));
        dp[index] = profit;
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        dp = vector<int>(prices.size(), -1);
        return compareProfit(prices, 0);
    }
};
*/

int main(){
    Solution sol;
    vector<int> input {1,2,3,0,2};
    cout << sol.maxProfit(input) << '\n';
    return 0;
}