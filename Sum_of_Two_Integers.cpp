#include <iostream>
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
    int getSum(int a, int b) {
    	if(b == 0)
    		return a;
        int exclusiveOr = a ^ b;
        int carry = (unsigned)(a & b) << 1;
        return getSum(exclusiveOr, carry);
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
	cout << sol.getSum(1, 2) << '\n';
	cout << sol.getSum(-1, 2) << '\n';
	cout << sol.getSum(1, -2) << '\n';
	cout << sol.getSum(-1, -2) << '\n';
	return 0;
}