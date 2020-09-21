#include <iostream>
#include <string>
#include <queue>
using namespace std;

class CombinationIterator {
public:
    queue<string> que;
    CombinationIterator(string characters, int combinationLength) {
        string tmp;
        DFS(que, characters, tmp, combinationLength, 0);
    }
    
    void DFS(queue<string>& que, string& chars, string& tmp, int length, int cur){
        if(cur > chars.size());
        else if(length == 0)
            que.push(tmp);
        else{
            tmp += chars[cur++];
            DFS(que, chars, tmp, --length, cur);
            tmp.pop_back();
            DFS(que, chars, tmp, ++length, cur);
        }
        return;
    }

    string next() {
        string ret = que.front();
        que.pop();
        return ret;
    }
    
    bool hasNext() {
        return !que.empty();
    }
};

int main(){
    CombinationIterator* obj = new CombinationIterator("abcde", 3);
    string param_1 = obj->next();
    bool param_2 = obj->hasNext();
    cout << param_1 << ' ' << boolalpha << param_2 << '\n';
    return 0;
}