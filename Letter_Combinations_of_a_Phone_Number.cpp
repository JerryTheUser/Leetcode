#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return vector<string>();
        unordered_map<char, std::string> table {{'2',"abc"}, {'3',"def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        int product = 1, iter = 1, idx = 0;
        for(auto& digit : digits)
            product *= table[digit].size();

        vector<string> ret(product, "");

        for(auto& digit : digits){
            idx = 0;
            product /= table[digit].size();
            for(int i=0 ; i<iter ; ++i){
                for(int j=0 ; j<table[digit].size() ; ++j){
                    for(int k=0 ; k<product ; ++k){
                        ret[idx++] += table[digit][j];
                    }
                }
            }
            iter *= table[digit].size();
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<string> result = sol.letterCombinations("234");
    for(auto& str : result)
        cout << str << ' ';
    cout << '\n';
    return 0;
}