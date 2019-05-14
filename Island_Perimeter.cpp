#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0;
        int height = grid.size();
        int width = grid[0].size();
        for(int i=0 ; i<height ; ++i){
            for(int j=0 ; j<width ; ++j){
                if(grid[i][j] == 1){
                    if(i == 0 || grid[i-1][j] == 0)
                        ++ret;
                    if(i == height-1 || grid[i+1][j] == 0)
                        ++ret;
                    if(j == 0 || grid[i][j-1] == 0)
                        ++ret;
                    if(j == width-1 || grid[i][j+1] == 0)
                        ++ret;
                }
                else
                    continue;
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0,1,0,0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << sol.islandPerimeter(grid) << '\n';
}