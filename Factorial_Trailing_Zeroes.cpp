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
    int trailingZeroes(int n) {
    	int ret = 0;
        while(n != 0){
        	ret += n / 5;
        	n /= 5;
        }
        return ret;
    }
};

int main(){
	Solution sol;
	cout << sol.trailingZeroes(3) << '\n';
	cout << sol.trailingZeroes(4) << '\n';
	cout << sol.trailingZeroes(5) << '\n';
	cout << sol.trailingZeroes(6) << '\n';
	return 0;
}