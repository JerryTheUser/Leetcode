#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> tmp(1, 0), ret;
        int layer = ceil(log2(label))+1;
        int low = 1, high = 1;
        bool right = true;
        for(int i=0 ; i<layer ; ++i){
            if(right){
                for(int it=low ; it<=high ; ++it)
                    tmp.push_back(it);
            }
            else{
                for(int it=high ; it>=low ; --it)
                    tmp.push_back(it);
            }
            right = !right;
            low = high+1;
            ++(high *= 2);
        }
        int index = 0;
        for(int i=0 ; i<tmp.size() ; ++i){
            if(tmp[i] == label){
                index = i;
                break;
            }
        }
        while(index != 0){
            ret.push_back(tmp[index]);
            index /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ret;
        int x = label;
        ret.push_back(x);
        while(x > 1){
            x = x /2;
            int tmp = pow(2, (int)log2(x));
            x = tmp + (tmp*2 - x - 1);
            ret.push_back(x);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> result = sol.pathInZigZagTree(16);
    for(auto& i : result)
        cout << i << ' ';
    return 0;
}