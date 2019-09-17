#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ret;
        if(S.empty())
            return ret;
        for(int i=0 ; i<=S.size() ; ++i)
            ret.push_back(i);
        bool change = true;
        while(change){
            change = false;
            for(int i=0 ; i<S.size() ; ++i){
                if(S[i] == 'D' && ret[i] < ret[i+1]){
                    swap(ret[i], ret[i+1]);
                    change = true;
                }
            }
        }
        return ret;
    }
};
*/
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ret;
        if(S.empty())
            return ret;
        int min = 0, max = S.size();
        for(int i=0 ; i<=S.size() ; ++i){
            if(S[i] == 'I'){
                ret.push_back(min);
                ++min;
            }
            else{
                ret.push_back(max);
                --max;
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    string input("IDID"), input2{"III"}, input3{"DDI"}, input4{"DIDI"}, input5{"DDDD"}, input6{"D"};
    vector<int> result = sol.diStringMatch(input6);
    for(auto&& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}