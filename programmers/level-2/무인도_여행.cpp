#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int n = maps.size(); // 세로
    int m = maps[0].size(); // 가로
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            // 바다거나 이미 방문 O
            if(maps[i][j] == 'X' || visited[i][j]) continue;
            
            // 방문 X 땅
            queue<pair<int, int>> q;
            visited[i][j] = true; 
            q.push({i,j});
            
            int sum = 0;
            
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                
                sum += maps[y][x] - '0';
                
                if((y-1 >= 0) && (maps[y-1][x] != 'X') && (!visited[y-1][x])){
                    visited[y-1][x] = true;
                    q.push({y-1,x});
                }
        
                if((y+1 < n) && (maps[y+1][x] != 'X') && (!visited[y+1][x])){
                    visited[y+1][x] = true;
                    q.push({y+1,x});
                }
        
                if((x-1 >= 0) && (maps[y][x-1] != 'X') && (!visited[y][x-1])){
                    visited[y][x-1] = true;
                    q.push({y, x-1});
                }
        
                if((x+1 < m) && (maps[y][x+1] != 'X') && (!visited[y][x+1])){
                    visited[y][x+1] = true;
                    q.push({y,x+1});
                }
            }
            answer.push_back(sum);
        }
    }
    
    if(answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}


// BFS 템플릿
// 1. 큐에 시작점 넣기
// 2. 방문 처리
// 3. 큐가 빌 때까지 반복
// 4. 큐에서 꺼낸 점을 기준으로 상하좌우 탐색