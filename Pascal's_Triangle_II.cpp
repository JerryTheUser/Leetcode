#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1, 1);
        for(int i=1 ; i<rowIndex+1 ; ++i)
            ret[i] = long(ret[i-1])*(rowIndex-i+1)/i;
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> result = sol.getRow(33);
    for(auto& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}