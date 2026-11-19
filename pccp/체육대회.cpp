#include <string>
#include <algorithm>
#include <vector>

// DFS : 모든 부호 조합을 빠짐없이 탐색하는 문제. DFS는 한 가지 조합을 끝까지 만든 뒤 돌아와 다음 조합을 확인하므로 코드가 자연스럽고, 별도의 방문 처리도 필요 X => 재귀 이용
using namespace std;

void DFS(const vector<vector<int>>& ability, int depth, int sum, int &answer, vector<bool>& visited){   
    if (depth == ability[0].size()) { //학생 모두 배정 완료 
        answer = max(answer, sum); // 최적 능력치 합 
        return;
    }
    
    for(int i = 0; i<ability.size(); i++){
        if(!visited[i]){ 
            visited[i] = true; // 방문 처리 
            
            DFS(ability, depth + 1, sum + ability[i][depth], answer, visited); // 운동 종류에 따라 다 배정했다가
            
            visited[i] = false; // 마지막으로 배정된 인원부터 한 명씩 배정된 걸 취소하고
        }
    }
}

int solution(vector<vector<int>> ability) {
    int answer = 0;
    vector<bool> visited(ability.size(), false);
    
    DFS(ability, 0, 0, answer, visited);
        
    return answer;
}

// 특정 ~가 탐색되었는지를 확인이 필요하다 => bool 형의 visited 배열 
// DFS 함수 자체는 대부분 저런 형식으로 구현됨. 보통 인자 5개, 재귀, 종료 조건 확인 이런 것들. 