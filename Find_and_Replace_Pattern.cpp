#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for(auto& word : words){
            if(pattern.size() != word.size())
                continue;
            unordered_map<char, char> mapping, reverse;
            bool flag = true;
            for(int i=0 ; i<pattern.size() ; ++i){
                auto iter = mapping.find(pattern[i]);
                if(iter == mapping.end()){
                    mapping[pattern[i]] = word[i];
                    auto iter2 = reverse.find(word[i]);
                    if(iter2 == reverse.end()){
                        reverse[word[i]] = pattern[i];
                    }
                    if(reverse[word[i]] != pattern[i]){
                        flag = false;
                        break;
                    }
                }
                else{
                    if(mapping[pattern[i]] != word[i]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                ret.push_back(word);
        }
        return ret;
    }
};
*/
class Solution {
private: 
    string convertString(string& str){
        string pos;
        int idx[256];
        fill_n(idx, 256, -1);
        for(int i=0 ; i<str.size() ; ++i){
            if(idx[str[i]] == -1){
                pos += i;
                idx[str[i]] = i;
            }
            else
                pos += idx[str[i]];
        }
        return pos;
    }

public:    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        string patternPos = convertString(pattern);
        for(auto& word : words){
            string wordPos = convertString(word);
            if(wordPos.compare(patternPos) == 0){
                ret.push_back(word);
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<string> input {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern("abb");
    vector<string> result = sol.findAndReplacePattern(input, pattern);
    for(auto& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}