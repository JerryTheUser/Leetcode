#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
private:
    int count;
    int ret;
    queue<pair<int, int>> first;
    queue<pair<int, int>> second;
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};

public:
    bool checkBoundary(vector<vector<int>>& grid, int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }

    void bfs(vector<vector<int>>& grid){
        bool changed = false;
        while(!first.empty()){
            pair<int, int> tmp = first.front();
            first.pop();
            int i = tmp.first, j = tmp.second;

            for(int index=0 ; index<4 ; ++index){
                int tmp_x = i+x[index];
                int tmp_y = j+y[index];
                if(checkBoundary(grid, tmp_x, tmp_y)){
                    if(grid[tmp_x][tmp_y] == 1){
                        changed = true;
                        grid[tmp_x][tmp_y] = 2;
                        --count;
                        second.push(make_pair(tmp_x, tmp_y));
                    }
                }
            }
        }
        
        if(changed){
            ++ret;
            first = second;
            second = queue<pair<int, int>>();
            bfs(grid);
        }
        else
            return;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        count = 0;
        ret = 0;
        for(int i=0 ; i<grid.size() ; ++i){
            for(int j=0 ; j<grid[0].size() ; ++j){
                if(grid[i][j] == 1) ++count;
                if(grid[i][j] == 2) first.push(make_pair(i,j));
            }
        }
        if(count == 0) return 0;
        else
            bfs(grid);
        
        if(count != 0) return -1;
        else return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> input2 {{2,1,1},{0,1,1},{1,0,1}};
    cout << sol.orangesRotting(input2) << '\n';
    return 0;
}