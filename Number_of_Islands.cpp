#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkBoundary(vector<vector<char>>& grid, int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(checkBoundary(grid, i, j)){
            if(grid[i][j] == '1'){
                grid[i][j] = '0';
                dfs(grid, i+1, j);
                dfs(grid, i, j+1);
                dfs(grid, i-1, j);
                dfs(grid, i, j-1);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for(int i=0 ; i<grid.size() ; ++i){
            for(int j=0 ; j<grid[0].size() ; ++j){
                if(grid[i][j] == '1'){
                    ++ret;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> input {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout << sol.numIslands(input) << '\n';
    return 0;
}