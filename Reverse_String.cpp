#include <iostream>
#include <vector>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for(int i=0 ; i<size/2 ; ++i){
            char tmp = s[i];
            s[i] = s[size-1-i]; 
            s[size-1-i] = tmp;
        }
    }
};

int main(){
    Solution sol;
    vector<char> A = {'h','e','l','l','o'};
    vector<char> B = {'H','a','n','n','a','h'};
    sol.reverseString(B);
    for(auto& i : B)
        cout << i << ' ';
    cout << '\n';    
}