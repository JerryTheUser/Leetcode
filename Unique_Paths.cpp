#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        vector<vector<int>> map(m, vector<int>(n, 1));
        for(int i=1 ; i<m ; ++i){
            for(int j=1 ; j<n ; ++j)
                map[i][j] = map[i-1][j] + map[i][j-1];
        }
        return map[m-1][n-1];
    }
};

int main(){
    Solution sol;
    cout << sol.uniquePaths(7, 3) << '\n';
    return 0;
}