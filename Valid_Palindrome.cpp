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
	string preProcess(string& str){
		string ret;
		for(int i=0 ; i<str.size() ; ++i){
			if(str[i] > 96 && str[i] < 123)
				ret.push_back(str[i]);
			else if(str[i] > 64 && str[i] < 91)
				ret.push_back(str[i] + 32);
			else if(str[i] > 47 && str[i] < 58)
				ret.push_back(str[i]);
			else;
		}
		return ret;
	}

	bool isValid(string& str){
		int left=0, right=str.size()-1;
		bool ret = true;
		while(left < right){
			if(str[left] != str[right]){
				ret = false;
				break;
			}
			++left;
			--right;
		}
		return ret;
	}

    bool isPalindrome(string s) {
    	string modified = preProcess(s);
    	return isValid(modified);     
    }
};

int main(){
	Solution sol;
	string str("A man, a plan, a canal: Panama"), str2("race a car"), str3("0P");
	cout << boolalpha << sol.isPalindrome(str3);
	return 0;
}