#include <iostream>
#include <vector> 
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public: 
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurence;
        unordered_set<int> times;
        for(auto&& i : arr){
            if(occurence[i] == 0)
                occurence[i] = 1;
            else
                ++occurence[i];
        }
        for(auto&& i : arr){
            times.insert(occurence[i]);
        }
        if(times.size() == occurence.size())
            return true;
        else
            return false;
    }
};

int main(){
    Solution sol;
    vector<int> input{1,2,2,1,1,3}, input2{-3,0,1,-3,1,1,1,-3,10,0}, input3{1, 2};
    cout << boolalpha << sol.uniqueOccurrences(input3) << '\n';
    return 0;
}