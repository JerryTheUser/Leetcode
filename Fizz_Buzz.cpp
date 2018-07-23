#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        int i;
        for(i=1 ; i<n+1 ; ++i){
            if(!(i%15))
                ret.push_back("FizzBuzz");
            else if(!(i%5))
                ret.push_back("Buzz");
            else if(!(i%3))
                ret.push_back("Fizz");
            else
                ret.push_back(std::to_string(i));
        }
        return ret;
    }

    vector<string> fizzBuzz_opt(int n) {
         vector<string> ret;
         int i;
         int a,b;
         for(i=1 ; i<n+1 ; ++i){
            a = i%5;
            b = i%3;
            if(!a && !b){
                ret.push_back("FizzBuzz");
                continue;
            }
            if(!a){
                ret.push_back("Buzz");
                continue;
            }
            if(!b){
                ret.push_back("Fizz");
                continue;
            }
            ret.push_back(std::to_string(i));
         }
         return ret;
     }
};

void print(vector<string> pr){
    //for_each(pr.begin(),pr.end(),[](string str){cout << str << endl;});
    auto run=pr.begin();
    for(;run!=pr.end();++run)
        cout << *run << endl;
    return;
}

int main(){
    Solution sol;
    vector<string> Ta = sol.fizzBuzz_opt(30);
    print(Ta);
    return 0;
}
