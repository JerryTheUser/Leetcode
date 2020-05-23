#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0, size = height.size();
        if(size == 0)
            return ret;
        vector<int> max_level(size, 0);

        int max_height = max_level[0] = height[0];
        for(int i=1 ; i<height.size() ; ++i){
            max_height = max(max_height, height[i]);
            max_level[i] = max_height;
        }

        max_height = height[size-1];
        max_level[size-1] = min(max_level[size-1], height[size-1]);
        for(int j=size-2 ; j>-1 ; --j){
            max_height = max(max_height, height[j]);
            max_level[j] = min(max_height, max_level[j]);
        }

        for(int i=0 ; i<size ; ++i)
            ret += (max_level[i] - height[i]);
        
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {0,1,0,2,1,0,1,3,2,1,2,1},
                input2 {9,8,7,6,5,4,3,2,1},
                input3 {1,2,3,4,5,6,7,8,9},
                input4 {0};
    cout << sol.trap(input) << '\n';
    cout << sol.trap(input2) << '\n';
    cout << sol.trap(input3) << '\n';
    cout << sol.trap(input4) << '\n';
    return 0;
}