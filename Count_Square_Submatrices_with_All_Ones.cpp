#include <iostream>
#include <vector> 
using namespace std;

/*
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int minor = min(m, n);
        int ret = 0;
        for(int iter=0 ; iter<minor ; ++iter){
            for(int i=0 ; i<m-iter ; ++i){
                for(int j=0 ; j<n-iter ; ++j){
                    if(matrix[i][j] == 1){
                        bool flag = true;
                        for(int k=0 ; k<=iter ; ++k){
                            for(int l=0 ; l<=iter ; ++l){
                                if(matrix[i+k][j+l] == 0){
                                    flag = false;
                                    break;
                                }
                                if(!flag)
                                    break;
                            }
                        }
                        if(flag)
                            ++ret;
                    }
                }
            }
        }
        return ret;
    }
};
*/

class Solution{
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        int ret = 0;
        for(int i=0 ; i<row ; ++i){
            for(int j=0 ; j<column ; ++j){
                if(matrix[i][j] == 1 && i != 0 && j != 0)
                    matrix[i][j] += min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1]));
                ret += matrix[i][j];
            }
        }
        return ret;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> input {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    cout << sol.countSquares(input) << '\n';
    return 0;
}
