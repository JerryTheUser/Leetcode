#include <iostream>
#include <vector>
#include <string>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int romanToInt(string s) {
        int index = 0, ret = 0;
        while(index != s.size()){
        	switch(s[index]){
        		case 'I' :
        			if(index < s.size()-1){
        				if(s[index+1] == 'V'){
        					ret += 4;
        					++index;
        				}
        				else if(s[index+1] == 'X'){
        					ret += 9;
        					++index;
        				}
        				else
        					ret += 1;
        			}
        			else ret += 1;
        			break;
        		case 'V' :
        			ret += 5;
        			break;
        		case 'X' :
        			if(index < s.size()-1){
        				if(s[index+1] == 'L'){
        					ret += 40;
        					++index;
        				}
        				else if(s[index+1] == 'C'){
        					ret += 90;
        					++index;
        				}
        				else
        					ret += 10;
        			}
        			else ret += 10;
        			break;
        		case 'L' :
        			ret += 50;
        			break;
        		case 'C' :
        			if(index < s.size()-1){
        				if(s[index+1] == 'D'){
        					ret += 400;
        					++index;
        				}
        				else if(s[index+1] == 'M'){
        					ret += 900;
        					++index;
        				}
        				else
        					ret += 100;
        			}
        			else ret += 100;
        			break;
        		case 'D' :
        			ret += 500;
        			break;
        		case 'M' :
        			ret += 1000;
        			break;
        		default : 
        			break;
        	}
        	++index;
        }	
        return ret;
    }
};

int main(){
	Solution sol;
	string input("MCMXCIV");
	string input2("III");
	string input3("IV");
	string input4("LVIII");
	cout << sol.romanToInt(input) << '\n';
	return 0;
}