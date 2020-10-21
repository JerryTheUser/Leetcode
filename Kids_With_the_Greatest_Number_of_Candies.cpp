#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ret(candies.size(), false);
        int threshold = INT_MIN;
        for(auto& candy : candies)
            threshold = max(threshold, candy);
        threshold = threshold - extraCandies;
        for(int i=0 ; i<candies.size() ; ++i)
            ret[i] = candies[i] >= threshold ? true : false;
        return ret;
    }
};