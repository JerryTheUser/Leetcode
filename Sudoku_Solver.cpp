#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    int* isValid(vector<vector<char>>& board, int i, int j){
        int* mapping = (int*)malloc(sizeof(int)*10);
        memset(mapping, 0, sizeof(int)*10);    
        for(int k=0 ; k<9 ; ++k){
            if(board[i][k] != '.') mapping[board[i][k]-'0'] = 1;
            if(board[k][j] != '.') mapping[board[k][j]-'0'] = 1;
        }
        for(int k=(i/3)*3 ; k<(i/3)*3+3 ; ++k)
            for(int l = (j/3)*3 ; l<(j/3)*3+3 ; ++l)
                if(board[k][l] != '.') mapping[board[k][l]-'0'] = 1;
        return mapping;
    }

    bool Sudoku(vector<vector<char>>& board, int i, int j){
        if(i == 8 && j == 9)
            return true;
        if(j == 9){
            ++i;
            j=0;
        }

        if(board[i][j] != '.'){
            if(Sudoku(board, i, j+1))
                return true;}
        else{
            int* mapping = isValid(board, i, j);
            for(int k=1 ; k<10 ; ++k){
                if(mapping[k] == 0){
                    board[i][j] = k+'0';
                    if(Sudoku(board, i, j+1))
                        return true;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        Sudoku(board, 0, 0);
        return;
    }
};
*/

class Solution {
public:
    bool row[9][9]={0}, col[9][9]={0}, cell[3][3][9]={0};
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < 9;i ++){
            for(int j = 0;j < 9;j ++){
                if(board[i][j] != '.'){
                    int d = board[i][j] - '1';
                    row[i][d] = col[j][d] = cell[i/3][j/3][d] = true;
                }
            }
        }
        dfs(board,0,0);
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j)
    {
        if(j == 9) return dfs(board, i+1, 0);
        if(i == 9) return true;
        if(board[i][j] != '.') return dfs(board, i, j+1);
        else{
            for(int k=0 ; k<9; ++k){
                if(!row[i][k] && !col[j][k] && !cell[i/3][j/3][k]){
                    row[i][k] = col[j][k] = cell[i/3][j/3][k] = true;
                    board[i][j] = '1' + k;
                    if(dfs(board, i, j+1))
                        return true;
                    else{
                        row[i][k] = col[j][k] = cell[i/3][j/3][k] = false;
                        board[i][j] = '.';
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> input {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    sol.solveSudoku(input);
    
    for(auto& i : input){
        for(auto& j : i)
            cout << j << ' ';
        cout << '\n';
    }
    cout << '\n';

    return 0;
}
