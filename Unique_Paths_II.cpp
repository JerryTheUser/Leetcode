#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(m == 1 && n == 1)
            return !obstacleGrid[0][0];
        
        vector<vector<long>> count(m, vector<long>(n, 0));
        count[0][0] = 1;
        for(int i=0 ; i<m ; ++i){
            if(obstacleGrid[i][0] == 1)
                break;
            count[i][0] = 1;
        }
        
        for(int i=0 ; i<n ; ++i){
            if(obstacleGrid[0][i] == 1)
                break;
            count[0][i] = 1;
        }

        for(int i=1 ; i<m ; ++i){
            for(int j=1 ; j<n ; ++j){
                if(obstacleGrid[i][j] != 1)
                    count[i][j] = count[i-1][j] + count[i][j-1];
            }
        }
        return count[m-1][n-1];
    }
};
*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int row = obstacleGrid.size(), column = obstacleGrid[0].size();
		vector<long> result(column);
		for (int i=0; i<row; ++i) {
			for (int j=0; j<column; ++j) {
				if (!obstacleGrid[i][j])
					result[j] = i || j ? (i ? result[j] : 0) + (j ? result[j-1] : 0) : 1;
                else
                    result[j] = 0;
			}
		}
		return result[column-1];
	}
};

int main(){
    Solution sol;
    vector<vector<int>> input {{0,0,0},{0,1,0},{0,0,0}};
    cout << sol.uniquePathsWithObstacles(input) << '\n';
    return 0;
}