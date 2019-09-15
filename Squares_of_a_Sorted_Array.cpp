#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret;
        if(A.size() == 0)
            return ret;
        else{
            int mid=0, left, right;
            for(int i=1 ; i<A.size() ; ++i){
                if(abs(A[i]) <= abs(A[mid]))
                    mid = i;
                else
                    break;
            }
            left = mid; right=mid+1;
            while(left>-1 && right<A.size()){
                if(abs(A[left]) < abs(A[right])){
                    ret.push_back(A[left]*A[left]);
                    --left;
                }
                else{
                    ret.push_back(A[right]*A[right]);
                    ++right;
                }
            }
            while(left>-1){
                ret.push_back(A[left]*A[left]);
                --left;
            }
            while(right<A.size()){
                ret.push_back(A[right]*A[right]);
                ++right;
            }
            return ret;
        }
    }
};

int main(){
    Solution sol;
    vector<int> input{-4,-1,0,3,10}, input2{-7,-3,2,3,11}, input3{-2,1}, input4{1}, input5{-3,-3,-2,1};
    vector<int> result = sol.sortedSquares(input);
    for(auto&& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}