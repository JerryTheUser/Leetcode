#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while(n > 0){
            product *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return product - sum;
    }
};

int main(){
    Solution sol;
    int input = 234, input2 = 4421;
    cout << sol.subtractProductAndSum(input) << '\n';
    cout << sol.subtractProductAndSum(input2) << '\n';
    return 0;
}