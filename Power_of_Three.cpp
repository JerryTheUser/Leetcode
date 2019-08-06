#include <iostream>
#include <vector>
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
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        else{
            return 1162261467 % n == 0;
        }
    }
};

int main()
{
    Solution sol;
    cout << boolalpha << sol.isPowerOfThree(4782968) << '\n';
    return 0;
}