#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 스스로 해결했지만 시간초과나서 80프로 스스로 해결 
vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string, int> rank;
    
    for(int i = 0; i < players.size(); i++){
        rank[players[i]] = i;
    }
    
    for(string call : callings){
        int called_idx = rank[call];
        int front_called_idx = called_idx - 1;
        
        string front_called = players[front_called_idx];
        
        players[front_called_idx] = call;
        players[called_idx] = front_called;
        
        rank[call] = front_called_idx;
        rank[front_called] = called_idx;
    }
    
    return players;
}