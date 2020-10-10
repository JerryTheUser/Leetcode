#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ret = arr;
        int max = ret[arr.size()-1];
        ret[arr.size()-1] = -1;
        for(int i=ret.size()-2 ; i>-1 ; --i){
            if(ret[i] == max) continue;
            else if(ret[i] < max) ret[i] = max;
            else{
                ret[i] = ret[i] ^ max;
                max = ret[i] ^ max;
                ret[i] = ret[i] ^ max;
            }
        }
        return ret;
    }
};