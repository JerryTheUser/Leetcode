#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) { 
        vector<int> ret;
        vector<bool> visited(n, false);
        for(auto& edge : edges)
            visited[edge[1]] = true;
        for(int i=0 ; i<n ; ++i)
            if(!visited[i]) ret.push_back(i);
        return ret;
    }
};

/*
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int> record;
        for(int i=0 ; i<n ; ++i) record.insert(i);
        for(auto& edge : edges)
            record.erase(edge[1]);
        vector<int> ret(record.begin(), record.end());
        return ret;
    }
};
*/

int main(){
    Solution sol;
    vector<vector<int>> input {{0,1},{0,2},{2,5},{3,4},{4,2}}, input2 {{0,1},{2,1},{3,1},{1,4},{2,4}};
    vector<int> result = sol.findSmallestSetOfVertices(5, input2);
    for(auto& i : result)
        cout << i << '\n';
    return 0;
}