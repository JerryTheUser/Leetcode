#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    static string toLowerCase(string str) {
        int size = str.length();
        int i;
        for(i=0 ; i<size ; ++i){
            if( (int)str[i]>64 && (int)str[i]<91){
                str[i] = (char)(str[i]+32); 
            }
        }
        return str;
    }
};

int main(){
    string sA("HellO WoRlD");
    string sB("ExCuSe Me");

    cout << Solution::toLowerCase(sA) << endl;
    cout << Solution::toLowerCase(sB) << endl;
    return 0;
}
