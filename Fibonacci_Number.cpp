#include <iostream>
#include <vector>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        else if(N == 1)
            return 1;
        else{
            int a = 0;
            int b = 1;
            int c = 1;
            for(int i=1 ; i<N ; ++i){
                c = a + b;
                a = b;
                b = c;
            }
            return c;
        }
    }
};

int main(){
    Solution sol;
    for(int i=0 ; i<31 ; ++i)
        cout << sol.fib(i) << '\n';
    return 0;
}