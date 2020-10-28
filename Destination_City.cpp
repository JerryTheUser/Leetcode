#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> in, out;
        for(auto& path : paths){
            in.insert(path[0]);
            out.insert(path[1]);
        }
        set<string> ret;
        set_difference(out.begin(), out.end(), in.begin(), in.end(), inserter(ret, ret.end()));
        return *(ret.begin());
    }
};