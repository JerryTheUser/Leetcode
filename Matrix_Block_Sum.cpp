#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    void recordValue(vector<vector<int>>& mat, vector<vector<int>>& ret, int i, int j, int K){
        int top = max(0, i-K), down = min(int(mat.size())-1, i+K),
            left = max(0, j-K), right = min(int(mat[0].size())-1, j+K);
        int acc = 0;
        for(int tmpi=top ; tmpi<=down ; ++tmpi)
             for(int tmpj=left ; tmpj<=right ; ++tmpj)
                acc += mat[tmpi][tmpj];
        ret[i][j] = acc;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> ret = mat;
        for(int i=0 ; i<mat.size() ; ++i){
            for(int j=0 ; j<mat[0].size() ; ++j){
                recordValue(mat, ret, i, j, K);
            }
        }
        return ret;
    }
};
*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ret = mat;
        int area[m+1][n+1];
        memset(area, 0, (m+1)*(n+1)*sizeof(int) );

        for(int i = 1; i<m+1; ++i)
            for(int j = 1; j<n+1; ++j)
                area[i][j] = mat[i-1][j-1] + area[i-1][j] + area[i][j-1] - area[i-1][j-1];

        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                int down = min(m, i+K+1),
                    right = min(n, j+K+1),
                    top = max(i-K,0),
                    left = max(j-K,0);
                ret[i][j] = area[down][right] - area[top][right] - area[down][left] + area[top][left];
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> result = sol.matrixBlockSum(input, 1);
    for(auto& i : result){
        for(auto& j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}