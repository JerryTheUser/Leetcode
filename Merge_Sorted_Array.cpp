#include <iostream>
#include <vector>
#include <string>
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m, --n;
        for(int i=nums1.size()-1 ; i>-1 ; --i){
        	if(m>=0 && n>=0){
        		if(nums1[m] > nums2[n]){
        			nums1[i] = nums1[m];
        			--m;
        		}
        		else{
        			nums1[i] = nums2[n];
        			--n;
        		}
        	}
        	else if(m>-1){
        		nums1[i] = nums1[m];
        		--m;
        	}
        	else if(n>-1){
        		nums1[i] = nums2[n];
        		--n;
        	}
        	else;
        }
        return;
    }
};

int main(){
	Solution sol;
	vector<int> input1{1,2,3,0}, input2{2};
	int m = 3, n = 1;
	sol.merge(input1, m, input2, n);
	for(auto&& i : input1)
		cout << i << ' ';
	cout << '\n';
	return 0;
}