#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ret = 0, sum = 0;
        sort(satisfaction.begin(), satisfaction.end(), [&](int a, int b){return a>b;});
        for(int i=0 ; i<satisfaction.size() ; ++i){
            sum += satisfaction[i];
            if(sum > -1)
                ret += sum;
            else break;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {-2,5,-1,0,3,-3};
    vector<int> input2 {-1,-4,-5};
    vector<int> input3 {4,3,2};
    vector<int> input4 {-1,-8,0,5,-9};
    cout << sol.maxSatisfaction(input) << '\n';
    cout << sol.maxSatisfaction(input2) << '\n';
    cout << sol.maxSatisfaction(input3) << '\n';
    cout << sol.maxSatisfaction(input4) << '\n';
    return 0;
}