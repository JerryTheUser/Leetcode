#include <iostream>
#include <cmath>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isHappy(int n) {
        int tmp = 0;
        int rem;
        while(1){
            tmp = 0;
            while(n != 0){
                rem = n % 10;
                tmp += pow(rem, 2);
                n = n/10;
            }
            n = tmp;
            if(n > 0 && n < 10){
                if(n == 1 || n == 7)
                    return true;
                else
                    return false;
            }
        }
    }
};

int main(){
    Solution sol;
    int a = 25;
    cout << sol.isHappy(a) << '\n';
    return 0;
}