#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    static int numJewelsInStones(string J, string S) {
        int i,j;
        int Ssize = S.length();
        int Jsize = J.length();
        int ret = 0;
        for(i=0 ; i<Ssize ; ++i){
            for(j=0 ; j<Jsize ; ++j){
                if(S[i] == J[j])
                    ++ret;
            } 
        }
        return ret;
    }  
};

int main(){
    std::string J1("aAb");
    std::string S1("aAAAbbbBBB");
    cout << Solution::numJewelsInStones(J1,S1) << endl;
    
    return 0;
}
