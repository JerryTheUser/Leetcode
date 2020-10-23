#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret;
        int h1[101]={0}, h2[101]={0};
        for(int i=0 ; i<nums.size() ; i++)
            h1[nums[i]]++;
        for(int i=1 ; i<101 ; i++)
            h2[i]=h1[i-1]+h2[i-1];
        for(int i=0 ; i<nums.size() ; i++)
            ret.push_back(h2[nums[i]]);
        return ret;   
    }
};

/*
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> map;
        map[sorted[0]] = 0;
        
        for(int i=1 ; i<sorted.size() ; ++i){
            if(sorted[i] != sorted[i-1])
                map[sorted[i]] = i;
        }
        
        for(int i=0 ; i<nums.size() ; ++i)
            ret[i] = map[nums[i]];
        return ret;
    }
};
*/