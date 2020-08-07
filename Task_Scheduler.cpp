#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> table(26, 0);
        for(auto&& task : tasks)
            ++table[task-'A'];
        
        sort(table.begin(), table.end(), greater<int>());

        int maxCount = 0, maxSize = table[0], len = tasks.size();
        for(int i=0 ; i<26 && maxSize == table[i] ; ++i)
            ++maxCount;

        return max(len, (maxSize-1) * (n+1) + maxCount);
    }
};

int main(){
    Solution sol;
    vector<char> input {'A','A','A','A','A','A','B','C','D','E','F','G'};
    vector<char> input2 {'A','A','A', 'B', 'B', 'B'};
    cout << sol.leastInterval(input2, 0) << '\n';
    return 0;
}