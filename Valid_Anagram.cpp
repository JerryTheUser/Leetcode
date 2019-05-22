#include <iostream>
#include <vector>
#include <string>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        int countA[26] = {0};
        int countB[26] = {0};
        int sizeA = s.size();
        int sizeB = t.size();
        if(sizeA != sizeB)
            return false;
        for(int i=0 ; i<sizeA ; ++i){
            //if(s[i] >= 97 && s[i] <=122)
            ++(countA[s[i]-97]);
            
            //if(t[i] >= 97 && t[i] <= 122)
            ++(countB[t[i]-97]);
        }

        for(int i=0 ; i<26 ; ++i)
            if(countA[i] != countB[i])
                return false;
        return true;
    } 
};

int main(){
    Solution sol;
    string A = "anagram";
    string B = "nagaram";
    string C = "cat";
    string D = "car";
    cout << sol.isAnagram(A, B) << '\n';
    cout << sol.isAnagram(C, D) << '\n';
}