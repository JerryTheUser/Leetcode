#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        size_t size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> table(size+2, vector<int>(size+2, 0));
        
        for(int l=1 ; l<=size ; ++l){ 
            for(int i=1 ; i<=size-l+1 ; ++i){
                int j = i+l-1;
                int tmp = nums[i-1]*nums[j+1];
                for(int k=i ; k<=j ; ++k){
                    table[i][j] = max(table[i][j], 
                    nums[k]*tmp + table[i][k-1] + table[k+1][j]);
                }
            }     
        }
        return table[1][size];
    }
};

int main(){
    Solution sol;
    vector<int> input{3,1,5,8};
    cout << sol.maxCoins(input) << '\n';
    return 0;
}

/*
0   1   2   3   4   5

0   0   0   0   0   0
0   3  30 159 167   0
0   0  15 135 159   0
0   0   0  40  48   0
0   0   0   0  40   0
0   0   0   0   0   0
*/
