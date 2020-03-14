#include <iostream>
#include <vector> 
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ret;
        int indexa = 0, indexb = 0;
        for(auto& ch : seq){
            if(ch == '('){
                if(indexa > indexb){
                    ++indexb;
                    ret.push_back(1);
                }
                else{
                    ++indexa;
                    ret.push_back(0);
                }
            }
            else{
                if(indexa > indexb){
                    --indexa;
                    ret.push_back(0);
                }
                else{
                    --indexb;
                    ret.push_back(1);
                }               
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    string input("(()())");
    vector<int> result = sol.maxDepthAfterSplit(input);
    for(auto& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}