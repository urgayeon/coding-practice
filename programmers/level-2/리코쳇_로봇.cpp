#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<string> board) {
    int n = board.size(); // 세로
    int m = board[0].size(); // 가로
    int goalX,goalY; // 목표지점 좌표 
    
    vector<vector<int>> distance(n, vector<int>(m, -1)); // 방문 처리용 배열 
    queue<pair<int, int>> q;
    
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(board[r][c] == 'R'){
                distance[r][c] = 0;
                q.push({r,c});
            }
            if(board[r][c] == 'G'){
                goalX = c;
                goalY = r;
            }
        }
    }
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(board[y][x] == 'G') return distance[y][x];
        
        int up = y;
        while (up - 1 >= 0 && board[up - 1][x] != 'D') {
            --up;
        }
        // 벽에 다다랐거나 D 만남 
        if (distance[up][x] == -1) {
            distance[up][x] = distance[y][x] + 1;
            q.push({up, x});
        }
        
        int down = y;
        while (down + 1 < n && board[down + 1][x] != 'D') {
            ++down;
        }

        if (distance[down][x] == -1) {
            distance[down][x] = distance[y][x] + 1;
            q.push({down, x});
        }
        
        int left = x;
        while (left - 1 >= 0 && board[y][left-1] != 'D') {
            --left;
        }

        if (distance[y][left] == -1) {
            distance[y][left] = distance[y][x] + 1;
            q.push({y, left});
        }
        
        int right = x;
        while (right + 1 < m && board[y][right+1] != 'D') {
            ++right;
        }

        if (distance[y][right] == -1) {
            distance[y][right] = distance[y][x] + 1;
            q.push({y, right});
        }
    }
    
    if(distance[goalY][goalX] == -1) return -1;
    else return distance[goalY][goalX];
}