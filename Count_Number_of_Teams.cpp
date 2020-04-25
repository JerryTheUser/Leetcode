#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int count(vector<int>& rating){
        int ret = 0;
        size_t size = rating.size();
        for(int i=0 ; i<size-2 ; ++i){
            for(int j=i+1 ; j<size-1 ; ++j){
                for(int k=j+1 ; k<size ; ++k){
                    if(rating[i]<rating[j] && rating[j]<rating[k])
                        ++ret;
                }
            }
        }
        return ret;
    }

    int numTeams(vector<int>& rating) {
        size_t size = rating.size();
        int ret = 0;
    
        if(size < 3)
            return 0;
        else{
            ret += count(rating);
            reverse(rating.begin(), rating.end());
            ret += count(rating);
        }
        return ret;
    }
};
*/

class Solution {
public:    
    int numTeams(vector<int>& rating) {
        int ret = 0;

        for(int i=1 ; i<rating.size()-1 ; ++i){
            int leftSmaller = 0, leftLarger = 0, rightSmaller = 0, rightLarger = 0;
            for(int j=0 ; j<rating.size() ; ++j){
                if(j<i){
                    if(rating[j]<rating[i])
                        ++leftSmaller;
                    else
                        ++leftLarger;
                }
                else if(j>i){
                    if(rating[j]<rating[i])
                        ++rightSmaller;
                    else
                        ++rightLarger;
                }
                else;
            }
            ret += leftLarger*rightSmaller;
            ret += leftSmaller*rightLarger;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {2,5,3,4,1};
    vector<int> input2 {1,2,3,4};
    cout << sol.numTeams(input) << '\n';
    cout << sol.numTeams(input2) << '\n';
    return 0;
}