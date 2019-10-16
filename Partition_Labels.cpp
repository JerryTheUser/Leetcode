#include <iostream>
#include <vector> 
#include <string>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    static bool cmp(const pair<int,int> &p1,const pair<int,int> &p2){
	    return p1.first < p2.first;
    }
    vector<int> partitionLabels(string S) {
        map<char, pair<int, int>> storage;
        vector<pair<int, int>> partition;
        vector<int> ret;
        if(S.size() != 0)
        {
            for(int i=0 ; i<S.size() ; ++i){
                auto iter = storage.find(S[i]);
                if(iter == storage.end())
                    storage[S[i]] = make_pair(i, i);
                else
                    storage[S[i]].second = i;
            }

            for(auto& i : storage)
                partition.push_back(i.second);
            
            sort(partition.begin(), partition.end(), this->cmp);
            
            pair<int, int> tmp = partition[0];
            for(auto& i : partition){
                if(i.first > tmp.second){
                    ret.push_back(tmp.second - tmp.first + 1);
                    tmp = i;
                }
                else if(i.second > tmp.second){
                    tmp.second = i.second;
                }
                else
                    continue;
            }
            ret.push_back(tmp.second - tmp.first + 1);
        }
        return ret;
    }
};
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        int endPoint[26];
        for(int i=0 ; i<S.size() ; ++i)
            endPoint[S[i] - 'a'] = i;

        int j = 0 , anchor = 0;
        for(int i=0 ; i<S.size() ; ++i){
            j = max(j, endPoint[S[i] - 'a']);
            if(i == j){
                ret.push_back(j - anchor + 1);
                anchor = i+1;
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    string input("ababcbacadefegdehijhklij"),input2("eccbbbbdec");
    vector<int> result = sol.partitionLabels(input2);
    for(auto&& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}