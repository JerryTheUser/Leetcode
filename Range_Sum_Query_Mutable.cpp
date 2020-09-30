#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums): nums(nums) {
        buildTree();
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        i += nums.size();
        segTree[i] += diff;
        for (i /= 2; i >= 1; i /= 2) {
            segTree[i] = segTree[i * 2] + segTree[2 * i + 1];
        }
    }
    
    int sumRange(int i, int j) {
        int ret = 0, n = nums.size();
        i += n; j += n;
        while (i <= j) {
            if (i & 1) ret += segTree[i++];
            if (!(j&1)) ret += segTree[j--];
            i /= 2; j /= 2;
        }
        return ret;
    }
private:
    vector<int>& nums;
    vector<int> segTree;
    
    void buildTree() {
        int size = nums.size();
        segTree.resize(2 * size, 0);
        for (int i=size, j=0 ; i<size*2 ; ++i, ++j)
            segTree[i] = nums[j];
        for (int i=size-1 ; i>0 ; --i)
            segTree[i] = segTree[2*i] + segTree[2*i+1];
    }
};

/*
class NumArray {
public:
    vector<int> table;
    NumArray(vector<int>& nums) {
        table = nums;
        for(int i=1 ; i<table.size() ; ++i)
            table[i] += table[i-1];   
    }
    
    void update(int i, int val) {
        int diff = val - table[i];
        for(int j=0 ; j<=i ; ++j)
            table[j] += diff;
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return table[j];
        else return table[j] - table[i-1];
    }
};
*/

int main(){
    vector<int> input {1,3,5};
    NumArray sol(input);
    return 0;
}