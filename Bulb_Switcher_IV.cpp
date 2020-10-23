#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        if(target.size() == 0) return 0;
        int ret = 0;
        bool state = false;
        for(int i=0 ; i<target.size() ; ++i){
            if(!state){
                if(target[i] == '1'){
                    ++ret;
                    state = !state;
                }
            }
            else{
                if(target[i] == '0'){
                    ++ret;
                    state = !state;
                }
            }
        }
        return ret;
    }
};