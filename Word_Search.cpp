#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkBoundary(vector<vector<char>>& board, int i, int j){
        return i>=0 && j>=0 && i<board.size() && j<board[0].size();
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index){
        if(!checkBoundary(board, i, j) || board[i][j] == '#' || board[i][j] != word[index])
            return false;
        else{
            if(index == word.size()-1)
                return true;
            bool ret = false;
            char tmp = board[i][j];
            board[i][j] = '#';
            ret = dfs(board, i+1, j, word, index+1) || 
                dfs(board, i, j+1, word, index+1) ||
                dfs(board, i-1, j, word, index+1) ||
                dfs(board, i, j-1, word, index+1);
            board[i][j] = tmp;
            return ret;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ret = false;
        for(int i=0 ; i<board.size() ; ++i){
            for(int j=0 ; j<board[0].size() ; ++j){
                if(board[i][j] == word[0]){
                    ret |= dfs(board, i, j, word, 0);
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> input {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string str("ABCCED");
    cout << boolalpha << sol.exist(input, str) << '\n';
    return 0;
}