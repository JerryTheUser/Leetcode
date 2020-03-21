#include <iostream>
#include <vector>
using namespace std;

class CustomStack {
private:
    int *stk;
    int size, top;
public:
    CustomStack(int maxSize) {
        stk = new int[maxSize];
        size = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(top < size-1)
            stk[++top] = x;
    }
    
    int pop() {
        if(top < 0)
            return -1;
        else
            return stk[top--];
    }
    
    void increment(int k, int val) {
        for(int iter=0 ; iter<=min(top, k-1); ++iter)
            stk[iter] += val;
    }
};

int main(){
    int maxSize = 3;
    CustomStack* obj = new CustomStack(maxSize);
    obj->push(2);
    int param = obj->pop();
    cout << param << '\n';
    return 0;
}