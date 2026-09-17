#include <string>
#include <vector>

// 그리디 알고리즘 적용 : 매순간 최선의 선택을 하는 것 

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int painted = 0; // 롤러가 칠한 마지막 번호가 어디인지
    
    for(int idx : section){
        if( idx > painted ){
            answer += 1;
            painted = idx + (m-1);
        }
    }
    return answer;
    
}
