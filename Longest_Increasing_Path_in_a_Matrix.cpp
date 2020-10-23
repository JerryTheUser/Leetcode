#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int ret;
    vector<vector<int>> record;
    
    void dfs(vector<vector<int>>& matrix, int i, int j){
        if(record[i][j] > 0) return;
        int tmp = 1;
        if(i>0 && matrix[i-1][j] > matrix[i][j]){
            dfs(matrix, i-1, j);
            tmp = max(tmp, record[i-1][j]+1);
        }
        if(j>0 && matrix[i][j-1] > matrix[i][j]){
            dfs(matrix, i, j-1);
            tmp = max(tmp, record[i][j-1]+1);
        }
        if(i<matrix.size()-1 && matrix[i+1][j] > matrix[i][j]){
            dfs(matrix, i+1, j);
            tmp = max(tmp, record[i+1][j]+1);
        }
        if(j<matrix[0].size()-1 && matrix[i][j+1] > matrix[i][j]){
            dfs(matrix, i, j+1);
            tmp = max(tmp, record[i][j+1]+1);
        }
        record[i][j] = tmp;
        ret = max(ret, record[i][j]);
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ret = 0;
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        record = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0 ; i<matrix.size() ; ++i){
            for(int j=0 ; j<matrix[0].size() ; ++j){
                dfs(matrix, i, j);
            }
        } 
        return ret;
    }
};
/*
class Solution {
public:
    vector<vector<int>> record;
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int pre){
        if(i<0 || i>= matrix.size() || j<0 || j>= matrix[0].size() || pre >= matrix[i][j]) return 0;
        if(record[i][j] > 0) return record[i][j];
        int val = matrix[i][j];
        record[i][j] =  max(dfs(matrix, i-1, j, val)+1,
                        max(dfs(matrix, i, j-1, val)+1,
                        max(dfs(matrix, i+1, j, val)+1,
                            dfs(matrix, i, j+1, val)+1)));

        return record[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int ret = 0;
        record = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0 ; i<matrix.size() ; ++i){
            for(int j=0 ; j<matrix[0].size() ; ++j){
                ret = max(ret, dfs(matrix, i, j, INT_MIN));
            }
        } 
        return ret;
    }
};
*/