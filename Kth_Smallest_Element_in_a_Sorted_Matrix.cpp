#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ret = matrix[0][0];
        int maxI = matrix.size();
        multimap<int, pair<int, int>> orderMap;

        for(int j=0 ; j<matrix[0].size() && j<k ; ++j){
            orderMap.emplace(matrix[0][j], make_pair(0, j));
        }

        while(!orderMap.empty() && k-- > 0){
            ret = orderMap.begin()->first;
            pair<int, int> tmp = orderMap.begin()->second;
            orderMap.erase(orderMap.begin());
            if(++tmp.first < maxI)
                orderMap.emplace(matrix[tmp.first][tmp.second], make_pair(tmp.first, tmp.second));
        }
        return ret;
    }
};
*/

class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int i = n-1, j = 0, ret = 0;
        while (i > -1 && j < n) {
            if (matrix[i][j] <= target) {
                ++ret += i;
                ++j;
            }
            else {
                --i;
            }
        }
        return ret;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty())
            return 0;
        int left = matrix[0][0], right = matrix[matrix.size()-1][matrix.size()-1];
        while (left < right) {
            int mid = (left + right)/2;
            int count = countLessEqual(matrix, mid);
            if (count < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input {{1,5,9}, {10,11,13}, {12,13,15}};
    vector<vector<int>> input2 {{1,2}, {1,3}};
    cout << sol.kthSmallest(input, 8) << '\n';
    return 0;
}