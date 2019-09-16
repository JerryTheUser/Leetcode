#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
class Solution {
public:
	void subProblem(unordered_set<string>& hashTable, string tiles, string str, int index){
		if(index == 0){
			if(!str.empty()){
				auto iter = hashTable.find(str);
				if(iter == hashTable.end()){
					hashTable.insert(str);
				}
			}
		}
		else{
			for(int i=0 ; i<tiles.size() ; ++i){
				string tmp = tiles;
				tmp.erase(tmp.begin()+i);
				str.push_back(tiles[i]);
				subProblem(hashTable, tmp, str, index-1);
				str.pop_back();
				subProblem(hashTable, tmp, str, index-1);
			}
		}	
	}

    int numTilePossibilities(string tiles) {
        if(tiles.empty())
        	return 0;
        unordered_set<string> hashTable;
        string tmp;
        subProblem(hashTable, tiles, tmp, tiles.size());
        return hashTable.size();
    }
};
*/
class Solution{
public:
	int fact[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
	unordered_set<string> hashTable;
	int uniquePerms(string& s) {
		int cnt[26] = {};
		for (auto ch : s) ++cnt[ch - 'A'];
		auto res = fact[s.size()];
		for (auto n : cnt) res /= fact[n];
		return res;
	}

	int dfs(string& str, string seq = "", int pos=0 ){
		if(pos >= str.size()){
			return hashTable.insert(seq).second ? uniquePerms(seq) : 0; 
		}
		return dfs(str, seq, pos+1) + dfs(str, seq+str[pos], pos+1);
	}

	int numTilePossibilities(string tiles) {
  		sort(begin(tiles), end(tiles));
  		return dfs(tiles) - 1;
	}
};

int main(){
	Solution sol;
	string input("AAB"), input2("AAABBC");
	//cout << sol.numTilePossibilities(input) << '\n';
	cout << sol.numTilePossibilities(input2) << '\n';
	return 0;
}