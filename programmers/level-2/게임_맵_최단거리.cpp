#include<vector>
#include <queue>
#include <utility>

using namespace std;

// BFS : 거리 비용이 같은 경우 처음 도착했을 때가 최적해임을 보장 

int solution(vector<vector<int> > maps)
{
    int n = maps.size(); // 세로
    int m = maps[0].size(); // 가로
    
    vector<vector<int>> distance(n, vector<int>(m, 0)); // m칸을 0개로 채우고, 그것을 n개의 줄 
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    distance[0][0] = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        // 다음 칸이 거리 계산에 방문되지 않은 위치만 반복하자 => distance[][] == 0 인지 검사 
        // 다음 칸이 유효한지(1)
        // 다음 칸이 범위를 벗어나진 않는지 
        if((y-1 >= 0) && (maps[y-1][x] == 1) && (distance[y-1][x] == 0)){
            distance[y-1][x] = distance[y][x] + 1;
            q.push({y-1,x});
        }
        
        if((y+1 < n) && (maps[y+1][x] == 1) && (distance[y+1][x] == 0)){
            distance[y+1][x] = distance[y][x] + 1;
            q.push({y+1,x});
        }
        
        if((x-1 >= 0) && (maps[y][x-1] == 1) && (distance[y][x-1] == 0)){
            distance[y][x-1] = distance[y][x] + 1;
            q.push({y, x-1});
        }
        
        if((x+1 < m) && (maps[y][x+1] == 1) && (distance[y][x+1] == 0)){
            distance[y][x+1] = distance[y][x] + 1;
            q.push({y,x+1});
        }
    }
    
    if(distance[n-1][m-1] == 0) return -1;
    return distance[n-1][m-1];
    
}