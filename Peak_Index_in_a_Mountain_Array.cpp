#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size()-1, mid;
        while(left < right){
            mid = (left+right)/2;
            if(A[mid]<A[mid+1])
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};

int main(){
    Solution sol;
    vector<int> input{0,0,0,1,2,1,0,0,0,0};
    cout << sol.peakIndexInMountainArray(input) << '\n';
    return 0;
}