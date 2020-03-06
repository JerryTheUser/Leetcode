#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void processString(string& input, int& real, int& image){
        string tmp;
        input = input.substr(0, input.size()-1);
        size_t found = input.find('+');
        tmp = input.substr(0, found);
        real = stoi(tmp);
        tmp = input.substr(found+1);
        image = stoi(tmp);
        return ;
    }
    string complexNumberMultiply(string a, string b) {
        string ret, tmp;
        int reala, realb, imagea, imageb;
        processString(a, reala, imagea);
        processString(b, realb, imageb);
        ret += to_string(reala*realb-imagea*imageb);
        ret += ('+');
        ret += to_string(reala*imageb+realb*imagea);
        ret += ('i');
        return ret;
    }
};

int main(){
    Solution sol;
    string input("1+1i"), input2("1+-1i");
    cout << sol.complexNumberMultiply(input, input2) << '\n';
    return 0;
}