#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    static vector<vector<int> > transpose(vector<vector<int> >& A) {
        int i,j;
        int size_i = A.size();
        int size_j = A[0].size();
        vector<vector<int> > ret;

        for(i=0 ; i<size_i ; ++i){
            for(j=0 ; j<size_j ; ++j){
                if(ret.size() <= j)ret.push_back(vector<int>());
                ret[j].push_back(A[i][j]);
            }
        }
        return ret;
    }
};

void print(vector<vector<int> >& A){
    int i,j;
    int i_size=A.size();
    int j_size=A[0].size();
    for(i=0 ; i<i_size ; ++i){
        for(j=0 ; j<j_size ; ++j){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> A {1,2,3,4};
    vector<int> B {4,5,6,5};
    vector<int> C {7,8,9,6};
    vector<int> D {10,11,12};
    vector<vector<int> > vec {A,B,C};
    vector<vector<int> > tmp;
    print(vec);
    tmp = Solution::transpose(vec);
    print(tmp);
    return 0;
}
