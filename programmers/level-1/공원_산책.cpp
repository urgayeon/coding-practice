#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool possible(const vector<string>& park, int x, int y){
    int row = park.size();
    int col = park[0].length();
    
    if ( y < 0 || y >= row || x < 0 || x >= col) return false;
    
    if (park[y][x] == 'X') return false;
    
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x,y;
    
    // 시작 좌표 찾기 
    for(int row = 0; row < park.size(); row ++){
        for(int col = 0; col < park[0].length(); col++){
            if(park[row][col] == 'S'){
                y = row;
                x = col;
            }
        }
    }
    
    for(string route : routes){
        // 임시 좌표 
        int nx = x;
        int ny = y;
        
        stringstream ss(route);
        
        // 방향 -> 이동거리 분리 
        string direction;
        int len;
        bool canMove = true;
        
        ss >> direction >> len;
        
        // len만큼 1칸씩 이동하기 
        for(int step = 0; step < len; step++){
            if(direction == "N") ny -= 1;
            else if(direction == "S") ny += 1;
            else if(direction == "W") nx -= 1;
            else if(direction == "E") nx += 1;
            
            // 이동 후 바로 유효성 검사 => false -> 바로 다음 명령어 (step for문 탈출)
            if(!possible(park, nx, ny)){
                canMove = false;
                break;
            }
        }
        // 하나의 명령어가 끝까지 canMove 면 좌표 확정 
        if(canMove){
            x = nx;
            y = ny;
        }
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}