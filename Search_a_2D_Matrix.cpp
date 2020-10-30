#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        int left = 0, right = m*n, mid, val;
        while(left < right){
            mid = left + (right - left) / 2;
            val = matrix[mid/n][mid%n];
            if(val == target) return true;
            else if(val < target)
                left = mid+1;
            else if(val > target)
                right = mid;
            else;
        }
        return false;
    }
};