#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> table;
    NumMatrix(vector<vector<int>>& matrix) {
        table = matrix;
        for(int i=0 ; i<table.size() ; ++i){
            for(int j=0 ; j<table[0].size() ; ++j){
                if(i == 0 && j == 0) continue;
                else if(i == 0) table[i][j] += table[i][j-1];
                else if(j == 0) table[i][j] += table[i-1][j];
                else table[i][j] += table[i][j-1] + table[i-1][j] - table[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 ==0) return table[row2][col2];
        else if(row1 == 0) return table[row2][col2] - table[row2][col1-1];
        else if(col1 ==0) return table[row2][col2] - table[row1-1][col2];
        else return table[row2][col2] - table[row2][col1-1] - table[row1-1][col2] + table[row1-1][col1-1];
    }
};