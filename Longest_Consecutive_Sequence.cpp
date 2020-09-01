#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> table(nums.begin(), nums.end());
        int ret = 0;
        for(auto& num : nums){
            if(!table.count(num))
                continue;
            int pre = num-1, next = num+1;
            while(table.count(pre)) table.erase(pre--);
            while(table.count(next)) table.erase(next++);
            ret = max(ret, next-pre-1);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {100, 4, 200, 1, 3, 2};
    int result = sol.longestConsecutive(input);
    cout << result << '\n';
    return 0;
}