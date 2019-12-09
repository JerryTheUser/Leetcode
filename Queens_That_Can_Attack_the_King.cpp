#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ret;
        vector<vector<bool>> chessboard(8, vector<bool>(8, false));
        for(auto& queen : queens)
            chessboard[queen[0]][queen[1]] = true;
        
        for(auto& i : chessboard){
            for(auto j : i){
                cout << j << ' ';
            }
            cout << '\n';
        }

        int i, j;
        i = king[0];
        while(i > -1){
            if(chessboard[i][king[1]]){
                ret.push_back(vector<int>{i, king[1]});
                break;
            }
            --i;
        }

        i = king[0];
        while(i < 8){
            if(chessboard[i][king[1]]){
                ret.push_back(vector<int>{i, king[1]});
                break;
            }
            ++i;
        }
        
        j = king[1];
        while(j > -1){
            if(chessboard[king[0]][j]){
                ret.push_back(vector<int>{king[0], j});
                break;
            }
            --j;
        }

        j = king[1];
        while(j < 8){
            if(chessboard[king[0]][j]){
                ret.push_back(vector<int>{king[0], j});
                break;
            }
            ++j;
        }
        
        i = king[0], j = king[1];
        while(i > -1 && j > -1){
            if(chessboard[i][j]){
                ret.push_back(vector<int>{i, j});
                break;
            }
            --i, --j;
        }

        i = king[0], j = king[1];
        while(i < 8 && j < 8){
            if(chessboard[i][j]){
                ret.push_back(vector<int>{i, j});
                break;
            }
            ++i, ++j;
        }

        i = king[0], j = king[1];
        while(i > -1 && j < 8){
            if(chessboard[i][j]){
                ret.push_back(vector<int>{i, j});
                break;
            }
            --i, ++j;
        }

        i = king[0], j = king[1];
        while(i < 8 && j > -1){
            if(chessboard[i][j]){
                ret.push_back(vector<int>{i, j});
                break;
            }
            ++i, --j;
        }

        return ret;
    }
};

/*
class Solution {
public:
    bool inBoard(const vector<int> &pos) {
        return pos[0] >= 0 && pos[0] < 8
            && pos[1] >= 0 && pos[1] < 8;
    }
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool board[8][8] = {};
        for (auto &queen : queens) {
            board[queen[0]][queen[1]] = true;
        }
        int dirs[8][2] = { 0, 1, 0, -1, 1, 0, -1, 0,
                          1, 1, 1, -1, -1, 1, -1, -1 };
        vector<vector<int>> r;
        for (int i = 0; i < 8; ++i) {
            auto dir = dirs[i];
            auto pos = king;
            while (inBoard(pos) && !board[pos[0]][pos[1]]) {
                pos[0] += dir[0];
                pos[1] += dir[1];
            }
            if (inBoard(pos))
                r.emplace_back(pos);
        }
        return r;
    }
};
*/

int main(){
    Solution sol;
    vector<vector<int>> queens {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
    vector<int> king {3,4};

    vector<vector<int>> queens2 {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}};
    vector<int> king2 {3,3};

    vector<vector<int>> result = sol.queensAttacktheKing(queens2, king2);
    for(auto&& i : result){
        cout << i[0] << ' ' << i[1];
        cout << '\n';
    }
    return 0;
}