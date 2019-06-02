#include <iostream>
#include <vector>
#include <array>
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
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        else
            return climbStairs(n-1) + climbStairs(n-2);
        
    }
};
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> record(n);
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        else{
            record[0] = 1;
            record[1] = 2;
            for(int i=2 ; i<n ; ++i)
               record[i] = record[i-1] + record[i-2];
            return record[n-1];
        }
        return 0;
    }
};

int main(){
    Solution sol;
    cout << sol.climbStairs(5) << '\n';
    return 0;
}