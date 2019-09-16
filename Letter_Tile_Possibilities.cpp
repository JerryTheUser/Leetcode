#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	void subProblem(unordered_set<string>& hashTable, string tiles, string str, int index){
		cout << str << '\n';
		if(index == tiles.size()){
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
				subProblem(hashTable, tmp, str, index+1);
				str.pop_back();
				subProblem(hashTable, tiles, str, index+1);
			}
		}	
	}

    int numTilePossibilities(string tiles) {
        if(tiles.empty())
        	return 0;
        unordered_set<string> hashTable;
        string tmp;
        subProblem(hashTable, tiles, tmp, 0);
        return hashTable.size();
    }
};

int main(){
	Solution sol;
	string input("AAB"), input2("AAABBC");
	cout << sol.numTilePossibilities(input) << '\n';
	//cout << sol.numTilePossibilities(input2) << '\n';
	return 0;
}