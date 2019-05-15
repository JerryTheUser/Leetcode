#include <iostream>
#include <vector>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int acc = 0;
        int ret = 0;
        int size = prices.size();
        if(size != 0){
            int base = prices[0];
            for(int i=1 ; i<size ; ++i){
                int diff = prices[i] - prices[i-1];
                if(diff > 0){
                    acc = (prices[i] - base);
                    if(acc > ret)
                        ret = acc;
                }
                else{
                    if(prices[i] < base){
                        base = prices[i];
                        acc = 0;
                    }
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> test = {};
    cout << sol.maxProfit(test) << '\n';
}