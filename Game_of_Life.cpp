#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j){
                int count = 0;
                for(int ri=max(0,i-1) ; ri<min(m,i+2) ; ++ri){
                    for(int ji=max(0,j-1) ; ji<min(n,j+2) ; ++ji){
                        count += board[ri][ji] & 1;
                    }
                }
                if(count == 3 || count - board[i][j] == 3)
                    board[i][j] |= 2;
            }
        }

        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j){
                board[i][j] >>= 1;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    sol.gameOfLife(input);
    for(auto& i : input){
        for(auto& j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}