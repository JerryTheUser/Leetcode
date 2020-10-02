#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        vector<int> count(26, 0);
        if(s.size() < p.size()) return ret;
        for(auto& i : p) ++count[i-'a'];
        int length = p.size(), cnt = length;
        for(int i=0 ; i<s.size() ; ++i){
            if(i >= length && count[s[i-length]-'a']++>=0) ++cnt;
            if(count[s[i]-'a']-->0) --cnt;
            if(cnt == 0)ret.push_back(i-length+1);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> results = sol.findAnagrams("cbaebabacd", "abc");
    for(auto& result : results)
        cout << result << ' ';
    cout << '\n';
    return 0;
}