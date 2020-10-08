#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        int ret = 0;
        for(int i=0 ; i<n/2 ; ++i)
            ret += n-(2*i+1);
        return ret;
    }
};