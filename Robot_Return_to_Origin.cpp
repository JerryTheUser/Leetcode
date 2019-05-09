#include <iostream>
using namespace std;
static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizontal = 0;
        for(auto& i : moves){
            switch(i){
                case 'U': 
                    ++vertical;
                    break;
                case 'D':
                    --vertical;
                    break;
                case 'R':
                    ++horizontal;
                    break;
                case 'L':
                    --horizontal;
                    break;
                default:
                    break;
            }
        }
        return ! (vertical || horizontal);
    }
};

int main(){
    string input = "UD";
    Solution sol;
    cout <<  boolalpha << sol.judgeCircle(input) << '\n';
    return 0;
}