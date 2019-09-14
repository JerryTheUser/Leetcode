#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp;
        for(int outer=0 ; outer<matrix.size()/2 ; ++outer){
            for(int inner=outer ; inner<(matrix.size()-(outer+1)) ; ++inner){
                tmp = matrix[outer][inner];
                matrix[outer][inner] = matrix[matrix.size()-inner-1][outer];
                matrix[matrix.size()-inner-1][outer] = matrix[matrix.size()-1-outer][matrix.size()-1-inner];
                matrix[matrix.size()-1-outer][matrix.size()-1-inner] = matrix[inner][matrix.size()-1-outer];
                matrix[inner][matrix.size()-1-outer] = tmp;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input{{1,2,3},{4,5,6},{7,8,9}}, 
                        input2{{5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
    sol.rotate(input2);
    for(auto&& i : input2){
        for(auto&& j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}