#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int left = 0, right = piles.size()-1;
        int ret = 0;
        while(left < right){
            ++left; --right;
            ret += piles[right--];
        }
        return ret;
    }
};


int main(){
    Solution sol;
    vector<int> piles {9,8,7,6,5,1,2,3,4}, piles2 {2,4,5};
    cout << sol.maxCoins(piles2) << '\n';
    return 0;
}