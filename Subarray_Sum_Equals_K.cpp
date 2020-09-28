#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        table[0] = 1;
        int sum = 0, ret = 0;
        for(auto& num : nums){
            sum += num;
            if(table.count(sum-k)!=0)
                ret += table[sum-k];
            if(table.count(sum)!=0)
                ++table[sum];
            else
                table[sum] = 1;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {1, 2, 1, 2, 1};
    cout << sol.subarraySum(input, 3) << '\n';
    return 0;
}