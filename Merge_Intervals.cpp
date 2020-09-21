#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if(intervals.size() == 0) return ret;

        sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a, const vector<int>& b){ return a[0]<b[0];});

        ret.push_back(intervals[0]);

        for(int i=1 ; i<intervals.size() ; ++i){
            if(intervals[i][0] > ret.back().at(1))
                ret.push_back(intervals[i]);
            else
                ret.back().at(1) = max(intervals[i][1], ret.back().at(1));
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input {{1,3},{2,6},{8,10},{15,18}}, input2 {{1,4}, {2,3}};
    vector<vector<int>> result = sol.merge(input);
    for(auto& i : result)
        cout << i[0] << ' ' << i[1] << '\n';
    return 0;
}