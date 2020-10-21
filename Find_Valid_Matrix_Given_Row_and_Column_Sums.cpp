#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ret(rowSum.size(), vector<int>(colSum.size(), 0));
        for(int i=0, j=0 ; i<rowSum.size() && j<colSum.size() ; ){
            ret[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ret[i][j];
            colSum[j] -= ret[i][j];
            i += rowSum[i] == 0;
            j += colSum[j] == 0;
        }
        return ret;
    }
};