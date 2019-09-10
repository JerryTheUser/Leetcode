#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        string modified{"$"};
        for(auto&& i : s){
            modified.push_back('#');
            modified.push_back(i);
        }
        modified.push_back('#');
        vector<int> record(modified.size(), 0);
        int center = 0, right = 0;
        for(int i=1 ; i<modified.size() ; ++i){
            if(i<right)
                record[i] = min(right-i, record[2*center-i]);
            while(modified[i+record[i]+1] == modified[i-record[i]-1])
                ++record[i];
            if(i+record[i] > right){
                right = i+record[i];
                center = i;
            }
        }
        for(auto&& i : record){
            ret += (i+1)/2;
        }
        return ret;
    }
    
};

int main()
{
	Solution sol;
	string str("aba"), str2("aaa"), str3("aa"), str4("abaab"), str5("abaa");
	cout << sol.countSubstrings(str) << '\n';
	cout << sol.countSubstrings(str2) << '\n';
	cout << sol.countSubstrings(str3) << '\n';
	cout << sol.countSubstrings(str4) << '\n';
	cout << sol.countSubstrings(str5) << '\n';
	return 0;
}