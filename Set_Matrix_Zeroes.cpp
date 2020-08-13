#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        bool col0 = true;
        for(int i=0 ; i<m ; ++i){
            if(matrix[i][0] == 0) col0 = false;
            for(int j=1 ; j<n ; ++j){
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i=m-1 ; i>=0 ; --i){
            for(int j=n-1 ; j>=1 ; --j)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if(!col0)
                matrix[i][0] = 0;
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(input);
    for(auto& i : input){
        for(auto& j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}