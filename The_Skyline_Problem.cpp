#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        vector<vector<int>> ret;
        multiset<int> heights;
        int maxHeight=0, currentHeight=0;
        
        for(auto& building : buildings){
            points.emplace_back(make_pair(building[0], -building[2]));
            points.emplace_back(make_pair(building[1], building[2]));
        }
        
        sort(points.begin(), points.end());

        heights.emplace(0);
        for(auto& point : points){
            if(point.second < 0)
                heights.emplace(-point.second);
            else
                heights.erase(heights.find(point.second));
            currentHeight = *heights.rbegin();
            if(currentHeight != maxHeight){
                ret.emplace_back(vector<int>{point.first, currentHeight});
                maxHeight = currentHeight;
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<vector<int>> result = sol.getSkyline(input);
    for(auto& items : result){
        for(auto& item : items)
            cout << item << ' ';
        cout << '\n';
    }
    return 0;
}

/*
2 -10
9 10
3 -15
7 15
5 -12
12 12
15 -10
20 10
19 -8
24 8

2 -10 -> {0, 10} c = 10 m = 0->10
3 -15 -> {0, 10 15} c = 15 m = 10->15
5 -12 -> {0, 10, 12, 15} c = 15 m = 15
7 15 -> {0, 10, 12} c = 12 m = 15->12
9 10 -> {0, 12} c = 12 m = 12
12 12 -> {0} c = 0 m = 12->0
15 -10 -> {0, 10} c = 10 m = 0->10 
19 -8 -> {0, 8, 10} c = 10 m = 10
20 10 -> {0, 8} c = 8 m = 10->8
24 8 -> {0} c = 0 m = 8->0
*/