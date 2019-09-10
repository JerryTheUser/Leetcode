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
    void onePath(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> current, int node){
        current.push_back(node);
        if(graph[node].size() == 0)
            result.push_back(current);
        else
            for(int i=0 ; i<graph[node].size() ; ++i)
                onePath(graph, result, current, graph[node][i]);
        return;
    }

    void recordPath(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> current, int node){
        if (node == graph.size()-1) {
            result.push_back(current);
            return;
        }
        for (int other : graph[node]) {
            current.push_back(other);
            recordPath(graph, result, current, other);
            current.pop_back();
        }
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        vector<int> tmp{0};
        //onePath(graph, ret, tmp, 0);
        recordPath(graph, ret, tmp, 0);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> A{{1,2},{3},{3},{}};
    vector<vector<int>> ret = sol.allPathsSourceTarget(A);
    for(auto&& i : ret){
        for(auto&& j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}