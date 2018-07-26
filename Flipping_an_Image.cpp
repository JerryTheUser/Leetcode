#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> ret;
        size_t size = A.size();
        int i,j;
        for(i=0 ; i<size ; ++i){
            vector<int> tmp;
            for(j=0 ; j<size ; ++j){
                tmp.push_back(A[i][size-j-1]^1);
            }
            ret.push_back(tmp);
        }
        return ret;
    }

    vector<vector<int>> flipAndInvertImage_opt(vector<vector<int>>& A) {
        for (auto & row : A) reverse(row.begin(), row.end());
        for (auto & row : A) for (int & i: row) i^=1;
        return A;
    }
};

void print(vector<vector<int>>& vec){
    int i;
    size_t size = vec.size();
    for(i=0 ; i<size ; ++i){
        for(auto j : vec[i])
            cout << j << " ";
        cout << '\n';
    }
}

int main(){
    vector<int> a = {0,0,1,0,1};
    vector<int> b = {1,0,1,1,0};
    vector<int> c = {0,0,1,0,1};
    vector<int> d = {1,1,1,1,0};
    vector<int> e = {0,0,0,0,0};

    vector<vector<int>> input = {a,b,c,d,e};
    Solution sol;
    vector<vector<int>> solve = sol.flipAndInvertImage(input);
    print(solve);
    return 0;
}
