#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> code{".-","-...","-.-.","-..",".","..-.","--.","....","..",
                        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                        "...","-","..-","...-",".--","-..-","-.--","--.."};
    
    void convertCode(vector<string>& converted, string& str){
        string store;
        for(int i=0 ; i<str.size() ; ++i)
            store += code[str[i]-97];
        converted.push_back(store);
        return;
    }

    int uniqueMorseRepresentations(vector<string>& words) {
        int ret = 0;
        unordered_map<string, int> hash;
        vector<string> modified;
        for(int i=0 ; i<words.size() ; ++i)
            convertCode(modified, words[i]);
        for(int i=0 ; i<modified.size() ; ++i){
            auto iter = hash.find(modified[i]);
            if(iter != hash.end())
                ++(iter->second);
            else{
                ++ret;
                hash[modified[i]] = 0;
            }
        }
        return ret;    
    }
};

int main(){
    Solution sol;
    vector<string> input{"gin", "zen", "gig", "msg"};
    cout << sol.uniqueMorseRepresentations(input) << '\n';
    return 0;
}