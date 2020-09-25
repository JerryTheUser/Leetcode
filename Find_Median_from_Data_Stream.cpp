#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <iterator>
using namespace std;

class MedianFinder {
    multiset<int> record;
    multiset<int>::iterator mid;
public:
    MedianFinder() :mid(record.end()) {
    }
    
    void addNum(int num) {
        const int count = record.size();
        record.insert(num);

        if(!count)
            mid = record.begin();
        else if(num < *mid)
            mid = count & 1 ? prev(mid) : mid; 
        else
            mid = count & 1 ? mid : next(mid); 
    }
    
    double findMedian() {
        int count = record.size();
        return count & 1 ? *mid : double((*mid + *next(mid))*0.5);
    }
};

/*
class MedianFinder {
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        low.push(num);
        high.push(low.top());
        low.pop();

        if(low.size() < high.size()){
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        return low.size() > high.size() ? low.top() : double((low.top() + high.top()) * 0.5);
    }
};
*/

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(3);
    obj->addNum(2);
    obj->addNum(4);
    cout << obj->findMedian() << '\n';
    return 0;
}