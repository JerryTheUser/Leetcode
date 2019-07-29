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
    int maxArea(vector<int>& height) {
        int ret = 0, area;
        int low = 0, high = height.size() - 1;
        while(low < high){
        	area = min(height[low], height[high]) * (high - low);
        	if(area > ret)
        		ret = area;
        	if(height[low] > height[high])
        		--high;
        	else
        		++low;;
        }
        return ret;
    }
};

int main(){
	Solution sol;
	vector<int> input {1,8,6,2,5,4,8,3,7};
	cout << sol.maxArea(input) << '\n';
	return 0;
}