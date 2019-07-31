#include <iostream>
#include <vector>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n!=0){
            if(n&1)
                ++ret;
            n = n >> 1;
        }
        return ret;
    }
};
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        while(n) {
            sum++;
            n &= n-1;
        }
        return sum;
    }
};

int main()
{
	Solution sol;
    uint32_t input =  0b00000000000000000000000000001011;
    uint32_t input2 = 0b00000000000000000000000010000000;
    uint32_t input3 = 0b11111111111111111111111111111101;
	cout << sol.hammingWeight(input3) << '\n';
	return 0;
}