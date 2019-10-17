#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
	string convertString(string& str){
        string pos;
        int idx[256];
        fill_n(idx, 256, -1);
        for(int i=0 ; i<str.size() ; ++i){
            if(idx[str[i]] == -1){
                pos += i;
                idx[str[i]] = i;
            }
            else
                pos += idx[str[i]];
        }
        return pos;
    }
public:
    bool isIsomorphic(string s, string t) {
        string sPos = convertString(s);
        string tPos = convertString(t);
        return sPos.compare(tPos) == 0;
    }
};

int main(){
    Solution sol;
    string input("paper"), input2("title");
    cout << boolalpha << sol.isIsomorphic(input, input2) << '\n';
    return 0;
}