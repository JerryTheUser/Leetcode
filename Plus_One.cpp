#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret = digits;
        int i;
        int size = ret.size();
        ++ret[size-1];
        for(i=size-1 ; i>0 ; --i){
            if(ret[i] > 9){
                ret[i] = 0;
                ++ret[i-1];
            }    
            else break;
        }
        if(ret[0] > 9){
            ret[0] = 1;
            ret.push_back(0);
        }
        return ret;
    }
};

void print(vector<int>& vec){
    for_each(vec.begin(),vec.end(),[](int n){ cout << n << " " ;});
}

int main(){
    Solution sol;
    vector<int> put{9,9,9,9,9,9,9};
    vector<int>Ta = sol.plusOne(put);
    print(Ta);
    return 0;
}
