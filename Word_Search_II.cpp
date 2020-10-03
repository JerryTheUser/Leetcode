#include <iostream>
#include <vector>
#include <string>
using namespace std;

class trie {
public:
    trie(){
        word = "";
        next = vector<trie*>(26, nullptr);
    };
    string word;
    vector<trie*> next;
};

class Solution {
public:
    void dfs(trie* root, vector<vector<char>>& board, int i, int j, vector<string>& ret){
        if(board[i][j] == '#' || root->next[board[i][j]-'a'] == nullptr) return;
        root = root->next[board[i][j] - 'a'];
        if(root->word != ""){
            ret.push_back(root->word);
            root->word = "";
        }   
        char save = board[i][j];
        board[i][j] = '#';
        if(i>0) dfs(root, board, i-1, j, ret);
        if(j>0) dfs(root, board, i, j-1, ret);
        if(i<board.size()-1) dfs(root, board, i+1, j, ret);
        if(j<board[0].size()-1) dfs(root, board, i, j+1, ret);
        board[i][j] = save;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        if(!board.size() || !board[0].size() || !words.size()) return ret;
        trie* root = new trie();
        for(auto& word : words)
            insert(root, word);
        for(int i=0 ; i<board.size() ; ++i){
            for(int j=0 ; j<board[0].size() ; ++j){
                dfs(root, board, i, j, ret);
            }
        }
        return ret;
    }

private:
    void insert(trie* root, string& word){
        for(auto& w : word){
            if(root->next[w-'a'] == nullptr)
                root->next[w-'a'] = new trie();
            root = root->next[w-'a'];
        }
        root->word = word;
    }
};


/*
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

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        for(int idx=0 ; idx<words.size() ; ++idx){
            bool found = false;
            for(int i=0 ; i<board.size() ; ++i){
                for(int j=0 ; j<board[0].size() ; ++j){
                    if(!found && board[i][j] == words[idx][0]){
                        if(dfs(board, i, j, words[idx], 0)){
                            ret.push_back(words[idx]);
                            found = true;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
*/

int main(){
    Solution sol;
    vector<vector<char>> board {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    }, test {{'a'}, {'b'}};
    vector<string> words {"oath","pea","eat","rain"}, test2 {"ab"};
    vector<string> results = sol.findWords(test, test2);
    for(auto& result : results)
        cout << result << ' ';
    cout << '\n';
}