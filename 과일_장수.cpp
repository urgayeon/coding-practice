#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    // ★ vector 내림차순 정렬 
    sort(score.begin(), score.end(), greater<int>());
    
    int box = score.size()/m;
    
    // 한 상자 속 최저 사과 점수 * m * 1
    
    for(int i = box*m-1; i >= 0; ){
        answer += score[i]*m;
        i -= m;
    }
    return answer;
}