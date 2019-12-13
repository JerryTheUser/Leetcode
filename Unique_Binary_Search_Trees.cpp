#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 1)
            return 1;
        else{
            int record[n+1];
            int acc = 0;
            record[0] = 1;
            record[1] = 1;
            for(int i=2 ; i<=n ; ++i){
                acc = 0;
                for(int j=1 ; j<=i ; ++j){
                    acc += record[j-1] * record[i-j];
                }
                record[i] = acc;
            }
            return record[n];
        }
    }
};

int main(){
    Solution sol;
    cout << sol.numTrees(3) << '\n';
    cout << sol.numTrees(4) << '\n';
    cout << sol.numTrees(5) << '\n';
    return 0;
}