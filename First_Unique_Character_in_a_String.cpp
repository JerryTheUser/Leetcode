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
    int firstUniqChar(string s) {
        int count[26] = {0};
        int size = s.size();
        int ret;
        for(auto& i : s)
            ++(count[i-97]);
        for(int i=0 ; i<size ; ++i){
            if(count[s[i]-97] == 1)
                return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    string A = "loveleetcode";
    string B = "leecode";
    cout << sol.firstUniqChar(B) << '\n';
}