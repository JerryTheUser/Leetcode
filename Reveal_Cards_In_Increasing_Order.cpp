#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
/*
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), [&](int a, int b){return a < b;});
        for(int i=2 ; i<deck.size() ; ++i){
            for(int j=deck.size()-1 ; j>deck.size()-i ; --j){
                swap(deck[j], deck[j-1]);
            }
        }
        return deck;
    }
};
*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), [&](int a, int b){return a < b;});
        
    }
};

int main(){
    Solution sol;
    vector<int> input{17,13,11,2,3,5,7}, input2{2, 3, 5, 7, 9, 11, 13};
    vector<int> result = sol.deckRevealedIncreasing(input2);
    for(auto& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}