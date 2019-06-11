#include <iostream>
#include <vector>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int Vmax[width] = {0}, Hmax[height] = {0};
        int ret = 0, tmp;
        for(int i=0 ; i<height ; ++i){
            for(int j=0; j<width ; ++j){
                if(Vmax[j] < grid[i][j])
                    Vmax[j] = grid[i][j];
                if(Hmax[i] < grid[i][j])
                    Hmax[i] = grid[i][j];
            }
        }
        for(int i=0 ; i<height ; ++i){
            for(int j=0; j<width ; ++j){
                tmp = min(Vmax[j], Hmax[i]);
                ret += tmp - grid[i][j];
            }
        }
        return ret;
    }
};

int main(){
    vector<vector<int>> grid{{3, 0, 8, 4},
                             {2, 4, 5, 7},
                             {9, 2, 6, 3},
                             {0, 3, 1, 0}};
    Solution sol;
    cout << sol.maxIncreaseKeepingSkyline(grid) << '\n';
    /*
    for(auto&& i : grid){
        for(auto&& j : i)
            cout << j << ' ';
        cout << '\n';
    }
    */
    return 0;
}