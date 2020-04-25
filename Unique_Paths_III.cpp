#include <iostream>
#include <vector> 
using namespace std;

class Solution {
private:
    int max_i, max_j, init_i, init_j, zeros;

    void init(vector<vector<int>>& grid){
        max_i = grid.size();
        max_j = grid[0].size();
        findZero(grid);
        findInit(grid);
        return;
    }

    void findInit(vector<vector<int>>& grid){
        for(int i=0 ; i<grid.size() ; ++i){
            for(int j=0 ; j<grid[0].size() ; ++j){
                if(grid[i][j] == 1){
                    init_i = i;
                    init_j = j;
                    return;
                }
            }
        }
    }

    void findZero(vector<vector<int>>& grid){
        zeros = 0;
        for(auto& i : grid)
            for(auto& j : i)
                if(j == 0)
                    ++zeros;
        return;
    }

    void printGrid(vector<vector<int>>& grid){
        for(auto& i : grid){
            for(auto& j : i)
                cout << j << ' ';
            cout << '\n';
        }
        cout << '\n';
    }

    bool checkBoundry(int i, int j){
        return (i>-1) && (i<max_i) && (j>-1) && (j<max_j);
    }

public:
    void subRoutine(vector<vector<int>>& grid, int i, int j, int current, int& ret){
        if(checkBoundry(i+1, j)){
            if(grid[i+1][j] == 2){
                if(current == zeros){
                    ++ret;
                    return;
                }
            }
            else if(grid[i+1][j] == 0){
                ++current;
                grid[i+1][j] = 1;
                subRoutine(grid, i+1, j, current, ret);
                grid[i+1][j] = 0;
                --current;
            }
            else;
        }

        if(checkBoundry(i, j+1)){
            if(grid[i][j+1] == 2){
                if(current == zeros){
                    ++ret;
                    return;
                }
            }
            else if(grid[i][j+1] == 0){
                ++current;
                grid[i][j+1] = 1;
                subRoutine(grid, i, j+1, current, ret);
                grid[i][j+1] = 0;
                --current;
            }
            else;
        }

        if(checkBoundry(i-1, j)){
            if(grid[i-1][j] == 2){
                if(current == zeros){
                    ++ret;
                    return;
                }
            }
            else if(grid[i-1][j] == 0){
                ++current;
                grid[i-1][j] = 1;
                subRoutine(grid, i-1, j, current, ret);
                grid[i-1][j] = 0;
                --current;
            }
            else;
        }

        if(checkBoundry(i, j-1)){
            if(grid[i][j-1] == 2){
                if(current == zeros){
                    ++ret;
                    return;
                }
            }
            else if(grid[i][j-1] == 0){
                ++current;
                grid[i][j-1] = 1;
                subRoutine(grid, i, j-1, current, ret);
                grid[i][j-1] = 0;
                --current;
            }
            else;
        }
        return;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        init(grid);
        int ret = 0;
        subRoutine(grid, init_i, init_j, 0, ret);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    vector<vector<int>> input2 {{0,1}, {2,0}};
    vector<vector<int>> input3 {{1,0,0,0},{0,0,0,0},{2,0,0,-1}};
    vector<vector<int>> input4 {{0,0,0,0,0,0,2,0,0,0},{0,0,0,0,0,0,0,0,1,0}};
    cout << sol.uniquePathsIII(input) << '\n';
    cout << sol.uniquePathsIII(input2) << '\n';
    cout << sol.uniquePathsIII(input3) << '\n';
    cout << sol.uniquePathsIII(input4) << '\n';
    return 0;
}