#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> table;
        for(int i=0 ; i<nums.size() ; ++i){
            while(!table.empty() && nums[table.back()] < nums[i])
                table.pop_back();
            table.push_back(i);
            if(!table.empty() && table.front() == i-k) table.pop_front();
            if(i >= k-1) ret.push_back(nums[table.front()]);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {1,3,-1,-3,5,3,6,7};
    vector<int> results = sol.maxSlidingWindow(input, 3);
    for(auto& result : results)
        cout << result << ' ';
    cout << '\n';
    return 0;
}