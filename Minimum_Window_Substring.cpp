#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 ||  t.size() == 0) return "";
        unordered_map<char, int> hash, window;
        for(auto& i : t){
            if(hash.find(i) == hash.end()) hash[i] = 1;
            else ++hash[i];
        }
        
        int require = hash.size();
        int formed = 0;
        int l=0, r=0;
        int length = -1;
        int start = 0;
        
        while(r<s.size()){
            if(window.find(s[r]) == window.end()) window[s[r]] = 1;
            else ++window[s[r]];
            
            if(hash.find(s[r]) != hash.end() && window[s[r]] == hash[s[r]])
                ++formed;

            while(l <= r && formed == require){
                if(length == -1 || r-l+1 < length){
                    length = r-l+1;
                    start = l;
                }           
                --window[s[l]];
                if(hash.find(s[l]) != hash.end() && window[s[l]] < hash[s[l]]) --formed;
                ++l; 
            }
            ++r;
        }
        return length == -1 ? "" : s.substr(start, length);
    } 
};

int main(){
    Solution sol;
    cout << sol.minWindow("abc", "b") << '\n';
    return 0;
}