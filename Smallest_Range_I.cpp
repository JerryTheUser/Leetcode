#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size() == 1)
            return 0;
        int minVal = *min_element(A.begin(), A.end());
        int maxVal = *max_element(A.begin(), A.end());
        int left = minVal + K;
        int right = maxVal - K;
        if(left >= right)
            return 0;
        else
            return right - left;
    }
};

int main(){
    Solution sol;
    vector<int> A = {1,3,6};
    vector<int> B = {5, 5, 5, 5, 5};
    int K = 8;
    cout << sol.smallestRangeI(B, K) << '\n';
}