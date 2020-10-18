#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        char ret = '0';
        for(int i=0 ; i<matrix.size() ; ++i){
            for(int j=0 ; j<matrix[0].size() ; ++j){  
                if(i!=0 && j!=0 && matrix[i][j] == '1')
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
                if(matrix[i][j] > ret) ret = matrix[i][j];
            }
        }
        return (ret-'0')*(ret-'0');
    }
};
