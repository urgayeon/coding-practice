#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int current_weight = 0;
    int time = 0;
    
    // length 만큼 칸 만들어주기 
    for(int i = 0; i < bridge_length; i++){
        bridge.push(0);
    }
    
    int truck = 0;
    
    while(truck < truck_weights.size()){
        time++;
        
        current_weight -= bridge.front();
        bridge.pop();
        
        if(current_weight + truck_weights[truck] <= weight){
            bridge.push(truck_weights[truck]);
            current_weight += truck_weights[truck];
            truck++;
        }
        else bridge.push(0); // 칸 수를 계속 유지해야하니까 값 자체는 있어야 함 
    } 
    return time + bridge_length;
}