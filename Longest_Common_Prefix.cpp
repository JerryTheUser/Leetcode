#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void findCommon(string& ret, string& input){
    	if(ret.size() == 0)
    		return;
    	else{
    		int i = min(ret.size(), input.size());
    		string tmp;
    		for(int j=0 ; j<i ; ++j){
    			if(ret[j] == input[j])
    				tmp.push_back(ret[j]);
    			else
    				break;
    		}
    		ret = tmp;
    	}
    	return;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        if(strs.size() == 0)
        	return ret;
        else if(strs.size() == 1)
        	return strs[0];
        else{
			ret = strs[0];
        	for(int i=1 ; i<strs.size() ; ++i){
        		findCommon(ret, strs[i]);
        		if(ret.size() == 0)
        			break;
        	}
        }
        return ret;
    }
};

int main(){
	Solution sol;
	vector<string> input{"flower","flow","flight"}, input2{"dog","racecar","car"};
	cout << sol.longestCommonPrefix(input2) << '\n';
	return 0;
}
