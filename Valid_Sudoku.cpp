#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unsigned char rows[9][9] = {0}, cols[9][9] = {0}, boxes[9][9] = {0}, val = 0;
        bool ret = true;
        for(int i=0 ; i<9 ; ++i){
            for(int j=0 ; j<9 ; ++j){
                if(board[i][j] != '.'){
                    val = board[i][j] - '1'; 
                    if(rows[i][val]++ || cols[j][val]++ || boxes[i/3*3+j/3][val]++)
                        return false;
                }
            }
        }
        return ret;
    }
};

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ret = true;
        unordered_set<char> set;

        for(int i=0 ; i<9 ; ++i){    
            for(int j=0 ; j<9 ; ++j){
                if(board[i][j] != '.'){
                    if(set.count(board[i][j]))
                        return false;
                    else
                        set.insert(board[i][j]);
                }
            }
            set.clear();
        }

        for(int i=0 ; i<9 ; ++i){    
            for(int j=0 ; j<9 ; ++j){
                if(board[j][i] != '.'){
                    if(set.count(board[j][i]))
                        return false;
                    else
                        set.insert(board[j][i]);
                }
            }
            set.clear();
        }
        
        for(int i=0 ; i<3 ; ++i){    
            for(int j=0 ; j<3 ; ++j){
                for(int k=0 ; k<3 ; ++k){
                    for(int l=0 ; l<3 ; ++l){
                        if(board[3*i+k][3*j+l] != '.'){
                            if(set.count(board[3*i+k][3*j+l]))
                                return false;
                            else
                                set.insert(board[3*i+k][3*j+l]);
                        }
                    }
                }
                set.clear();
            }
        }
        return ret;
    }
};
*/

int main(){
    Solution sol;
    vector<vector<char>> sudoku {
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
    cout << boolalpha << sol.isValidSudoku(sudoku) << '\n';
    return 0; 
}