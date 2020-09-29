#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size()-1;
        for(int i=2 ; i<cost.size() ; ++i)
            cost[i] = cost[i] + min(cost[i-1], cost[i-2]);
        return min(cost[size], cost[size-1]);
    }
};
