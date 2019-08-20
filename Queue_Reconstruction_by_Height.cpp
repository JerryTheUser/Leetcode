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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    	if(people.size() == 0 || people.size() == 1)
    		return people;
        sort(people.begin(), people.end(),
        	[](vector<int>& a, vector<int>& b){
        		return a[0] > b[0] || ( a[0] == b[0] && a[1] < b[1] );
        		/*
   				if(a[0] > b[0])
					return true;
				else if(a[0] == b[0])
					return (a[1] < b[1]);
				else
					return false;
				*/
        });
        
        vector<vector<int>> ret;
        for(auto&& person : people)
        	ret.insert(ret.begin()+person[1], person);
        /*
        for(int i=1 ; i<people.size() ; ++i){
        	int tmp = i;
        	while(people[tmp][1] < tmp && people[tmp][0] < people[tmp-1][0]){
        		swap(people[tmp], people[tmp-1]);
        		--tmp;
        	}
        }
        return people;
    	*/
        return ret;
    }
};

int main()
{
	Solution sol;
	vector<vector<int>> result, input{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}}, input2{{1,1}}, input3{}, input4{{2, 1}, {3, 0}}, input5{{3, 0}, {2, 1}};
	result = sol.reconstructQueue(input);
	for(auto& i : result){
		for(auto& j : i){
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}