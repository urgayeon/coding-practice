#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> process;
    priority_queue<int> pq;
    int cnt = 0;
        
    for(int i = 0; i<priorities.size(); i++){
        process.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(!process.empty()){
        pair<int, int> standard = process.front();
        int top_pq = pq.top();
        
        if(standard.second < top_pq){
            process.pop();
            process.push(standard);
        } 
        // 같다면 
        else{
            cnt++;
            if(standard.first == location){
                return cnt;
            }
            process.pop();
            pq.pop();
        }
    }
}