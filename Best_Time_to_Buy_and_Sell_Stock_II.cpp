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
        int size = prices.size();
        if(size == 0)
            return 0;
        else{
            int base = prices[0];
            int diff = 0;
            int acc = 0;
            for(int i=1 ; i<size ; ++i){
                diff = prices[i] - prices[i-1];
                if(diff > 0)
                    acc += diff;
                else
                    base = prices[i];
            }
            return acc;
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> A = {7, 1, 5, 3, 6, 4};
    vector<int> B = {1, 2, 3, 4, 5};
    vector<int> C = {5, 4, 3, 2, 1};
    vector<int> test = {};
    cout << sol.maxProfit(A) << '\n';
    cout << sol.maxProfit(B) << '\n';
    cout << sol.maxProfit(C) << '\n';
}