#include <iostream>
#include <vector>
#include <queue>
#include <algothrm>
using namespace std;
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto& num : nums)
            pq.push(num);
        while(k > 1){
            pq.pop();
            --k;
        }
        return pq.top();
    }
};
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end()-k, nums.end());
        return *(nums.end()-k);
    }
};

int main(){
    Solution sol;
    vector<int> input{3,2,3,1,2,4,5,5,6}, input2{3,2,1,5,6,4};
    int k = 4;
    cout << sol.findKthLargest(input2, 2) << '\n';
    return 0;
}