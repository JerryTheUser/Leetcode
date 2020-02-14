#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> tmp;
public:
    void sortingAlgo(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& ret){
        tmp.clear();
        int itmp = i, jtmp = j;
        while(itmp<mat.size() && jtmp<mat[0].size()){
            tmp.push_back(mat[itmp][jtmp]);
            ++itmp; ++jtmp;
        }
        sort(tmp.begin(), tmp.end());
        for(auto& item : tmp){
            ret[i][j] = item;
            ++i; ++j;
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> ret = mat;
        for(int i=0 ; i<mat.size() ; ++i)
            sortingAlgo(i, 0, mat, ret);
        for(int j=0 ; j<mat[0].size() ; ++j)
            sortingAlgo(0, j, mat, ret);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    vector<vector<int>> result = sol.diagonalSort(mat);
    for(auto& i : result){
        for(auto& j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}