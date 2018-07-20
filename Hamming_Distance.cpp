#include <iostream>
#include <bitset>
using std::cout;
using std::endl;

class Solution {
public:
    static int hammingDistance(int x, int y) {
        int ret = 0;
        int diff = x^y;
        while(diff != 0){
            if(diff%2)
                ++ret;
            diff = diff >> 1;
        }
        return ret;
    }
};

int main(){
    cout << Solution::hammingDistance(1,4) << endl;
    cout << Solution::hammingDistance(23,18) << endl;
    return 0;
}
