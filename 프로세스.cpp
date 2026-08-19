#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> process;
    priority_queue<int> pq; // 자동으로 정렬 (내림차순) 
    int count = 0;
    
    for(int i = 0; i<priorities.size(); i++){
        process.push({priorities[i],i}); // {우선순위, 인덱스}
        pq.push(priorities[i]);
    }
    
    while(!process.empty()){
        pair<int, int> current = process.front();
        int top_p = pq.top();
        
        if(current.first < top_p){
            process.pop();
            process.push(current);
        }
        else{
            count++;
            if(current.second == location) answer = count;
            process.pop();
            pq.pop();
        }
    }
    return answer;
}