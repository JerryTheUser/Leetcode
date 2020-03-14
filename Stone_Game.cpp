#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
private:
    typedef pair<int, int> ele;
public:
    bool stoneGame(vector<int>& piles) {
        size_t size = piles.size();
        vector<vector<ele>> DP(size, vector<ele>(size, make_pair(0, 0)));
        for(int j=0 ; j<size ; ++j){
            DP[0][j].first = piles[j];
        }
        
        for(int i=1 ; i<size ; ++i){
            for(int j=i ; j<size ; ++j){
                DP[i][j].first = max((piles[j-i] + DP[i-1][j].second), (piles[j] + DP[i-1][j-1].second));
                DP[i][j].second = min(DP[i-1][j-1].first, DP[i-1][j].first);
            }
        }
        return DP[size-1][size-1].first > DP[size-1][size-1].second;
    }
};

int main(){
    Solution sol;
    vector<int> input {5,3,4,5};
    cout << boolalpha << sol.stoneGame(input) << '\n';
    return 0;
}


/*
(5 3 4 5) -> [ 9 ] [ 8 ]

(5 3 4) -> [ 8 ] [ 4 ]
(3 4 5) -> [ 8 ] [ 4 ]

(5 3) -> [ 5 ] [ 3 ]
(3 4) -> [ 4 ] [ 3 ]
(4 5) -> [ 5 ] [ 4 ]

(5) -> [ 5 ] [ 0 ]
(3) -> [ 3 ] [ 0 ]
(4) -> [ 4 ] [ 0 ]
(5) -> [ 5 ] [ 0 ]
*/