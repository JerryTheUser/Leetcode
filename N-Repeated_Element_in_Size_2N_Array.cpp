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
    bool check(vector<int>& A, int num){
        int size = A.size();
        int acc = 0;
        for(auto& i : A)
            if(i == num)
                ++acc;
        if(acc == (size/2))
            return true;
        else
            return false;
    }
    int repeatedNTimes(vector<int>& A) {
        int size = A.size();
        int acc = 0;
        int base;
        if(size != 0){  
            base = A[0];
            for(int i=1 ; i<size ; ++i){
                if(A[i] == base)
                    ++acc;
                else{
                    --acc;
                    if(acc < 0){
                        base = A[i];
                        acc = 0;
                    }
                }
            }
            if(acc >= 0 && check(A, base))
                return base;
            else{
                if(check(A, A[0]))
                    return A[0];
                if(check(A, A[size-1]))
                    return A[size-1];
            }
            return 0;
        }
        else
            return 0;
    }
};

int main(){
    Solution sol;
    vector<int> A = {5,1,5,2,5,3,5,4};
    vector<int> B = {2,1,2,5,3,2};
    vector<int> C = {1,2,3,3};
    vector<int> D = {1,5,5,2,5,3};
    vector<int> E = {5,5,5,1,2,3};
    cout << sol.repeatedNTimes(C) << '\n';
    cout << sol.repeatedNTimes(B) << '\n';
    cout << sol.repeatedNTimes(A) << '\n';
    cout << sol.repeatedNTimes(D) << '\n';
    cout << sol.repeatedNTimes(E) << '\n';
    return 0;
}