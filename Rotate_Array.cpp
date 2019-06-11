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
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size!=0 && k != 0){
            int store, index;
            for(int i=0, run=0 ; run<size ; ++i){
                store = nums[i];
                index = (i+k)%size;
                while(index != i){
                    swap(store, nums[index]);
                    ++run;
                    index = (index+k)%size;
                }
                swap(store, nums[index]);
                ++run;
            }
        return;
        }
    }
};

int main(){
    Solution sol;
    vector<int> A{1,2,3,4,5,6,7};
    vector<int> B{-1,-100,3,99};
    vector<int> C{1};
    int k = 0;
    sol.rotate(A,k);
    for(auto&& i : A)
        cout << i << ' ';
    cout << '\n';
    return 0;
}