#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int ret = 0;
        while(num != 0){
            if(num & 1)
                --num;
            else
                num /= 2;
            ++ret;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    cout << sol.numberOfSteps(123) << '\n';
    return 0;
}