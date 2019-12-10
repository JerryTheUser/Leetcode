#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        vector<vector<string>> ret;
        for(auto& str : strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            table[sorted].push_back(str);
        }
        for(auto& item : table)
            ret.push_back(item.second);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<string> input {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(input);
    for(auto& group : result){
        for(auto& str : group){
            cout << str << ' ';
        }
        cout << '\n';
    }
    return 0;
}