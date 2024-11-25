// https://www.programiz.com/cpp-programming/priority-queue

#include<iostream>
#include<queue>

using namespace std;

int main(){

    priority_queue<int> maxHeap;// arranges the elements in ascending order (makes the largest element at the top with the highest priority)
    priority_queue<int,vector<int>,greater<int>> minHeap;// arranges elements in descending order( makes the smallest element at top with the highest priority)

    maxHeap.push(3);
    maxHeap.push(4);
    maxHeap.push(6);

    minHeap.push(3);
    minHeap.push(4);
    minHeap.push(6);

    int size=maxHeap.size();
    
    for(int i=0;i<size;i++){
       cout<<maxHeap.top()<<endl;
        maxHeap.pop()hello this is the ;
    }

    size=minHeap.size();
    
    for(int i=0;i<size;i++){
        cout<<minHeap.top()<<endl;
        minHeap.pop();
    }

   while(!maxHeap.empty()) {
        cout << maxHeap.top() << ", ";
        maxHeap.pop();
    }
    cout<<endl;
    return 0;

}