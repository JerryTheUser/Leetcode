#include <iostream>
#include <string> 
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for(auto& i : s){
        	ret *= 26;
        	ret += (i - 64);
        }
        return ret;
    }
};
*/
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for(int i=0 ; i<s.size() ; ret = ret*26 + s.at(i) - 'A' + 1, ++i);
        return ret;
    }
};

int main(){
	Solution sol;
	string str("ZY");
	string str2("AB");
	string str3("A");
	string str4("AA");
	cout << sol.titleToNumber(str) << '\n';
	cout << sol.titleToNumber(str2) << '\n';
	cout << sol.titleToNumber(str3) << '\n';
	cout << sol.titleToNumber(str4) << '\n';
	return 0;
}