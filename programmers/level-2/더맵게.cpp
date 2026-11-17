#include <string>
#include <vector>
#include <queue>

// "우선순위 큐" -> Heap
// minHeap을 이용함 
// 작은 것들 차례대로 꺼내야하니... minHeap을 이용해야하는 것. 

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i<scoville.size(); i++){
        minHeap.push(scoville[i]);
    }
    
    
    while( minHeap.top() < K ){
        if(minHeap.size() < 2) return -1;
        
        int smallest = minHeap.top();
        minHeap.pop();
        minHeap.push(smallest + (minHeap.top()*2));
        minHeap.pop();
        
        answer++;
    }
    return answer;
}