#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    queue<int> waiting;
    
    for(int t: truck_weights){
        waiting.push(t);
    }
    
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }
    
    int sum = 0;
    int remaining = truck_weights.size();
    
     while (remaining > 0) {
        answer++;
         
         if(bridge.front() != 0) {
             sum -= bridge.front();
             remaining--;
         }   
         
         bridge.pop();

        if (!waiting.empty() && (sum + waiting.front() <= weight)) {
            bridge.push(waiting.front());
            sum += waiting.front();
            waiting.pop();
        } else {
            bridge.push(0);
        }
    }

    return answer;
}